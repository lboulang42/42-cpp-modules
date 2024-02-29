/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:26:58 by lboulang          #+#    #+#             */
/*   Updated: 2024/02/29 13:31:35 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/*clean*/

/*check if date exist / could exist*/
bool isDateValid(int year, int month, int day) {
	if (year < 2009 || year > 2024)
		return false;
	if( month > 12 || day > 31 || month < 1 || day < 1)
		return false;
	if (day == 31 && (month == 2 || month == 4 || month == 6 || month == 9 || month == 11))
		return false;
	if (month == 2 && day > 29) 
		return false;
	if (month == 2 && day == 29 && (year%100)%4 != 0)
		return  false;
	return true;
}

/*check if date format is YYYY-MM-DD*/
bool isDateFormat(std::string &str)
{
	for (size_t i = 0; i < str.length(); i++) {
			if (i == 4 || i == 7)
			{
				if (str[i] != '-')
					return (false);
			}
			else if (!isdigit(str[i]))
				return (false);
	}
	return (true);
}

/*convert year, month, day as string in date format*/
std::string strtodate(int year, int month, int day)
{
	std::string tmp = ToString<int>(year) + "-";
	if (month < 10)
		tmp += "0";
	tmp += ToString<int>(month) + "-";
	if (day < 10)
		tmp += "0";
	tmp += ToString<int>(day);
	return tmp;
}

/*check if value format is positive int / float*/
bool isValueFormat(std::string &value)
{
	bool hasDecimalPoint = false;
	for (size_t i = 0; i < value.length(); i++)
	{
		if (!isdigit(value[i]) && value[i] != '.' && value[i] != '-')
			return false;
		if (value[i] == '.')
		{
			if (hasDecimalPoint)
				return false;
			hasDecimalPoint = true;
		}
	}
	return true;
}

/*load data.csv file*/
void	BitcoinExchange::loadCSV(void)
{
	std::ifstream data("data.csv");
	if (!data.is_open())
		throw BTCExceptions::CSVExcept();
	std::string linedata;
	getline(data, linedata);
	if (linedata != "date,exchange_rate")
		throw BTCExceptions::CSVExcept();
	while (getline(data, linedata))
	{
		if (linedata.size() < 12)//check if too short
			throw BTCExceptions::CSVExcept();
		if (linedata.find(",") == std::string::npos)//check if no separator
			throw BTCExceptions::CSVExcept();
		std::string date = linedata.substr(0, 10);
		if (!isDateFormat(date))
			throw BTCExceptions::CSVExcept();
		std::string value = linedata.substr(11);
		if (!isValueFormat(value))
			throw BTCExceptions::CSVExcept();
		_data[date] = value;
	}
	data.close();
}

/*get the value linked to the searched day from the map*/
std::string BitcoinExchange::getValueFromMap(int _Year, int _Month, int _Day)
{
	std::string tmp;

	/*check in the month*/
	for (int d = _Day-1; d > 0; d--)
	{
		tmp = strtodate(_Year, _Month, d);
		if (_data.find(tmp) != _data.end())
			return (_data[tmp]);
	}
	/*check in the year*/
	for (int m = _Month-1; m > 0; m--)
	{
		for (int d = 31; d > 0; d--)
		{
			tmp = strtodate(_Year, m, d);
			if (_data.find(tmp) != _data.end())
				return (_data[tmp]);
		}
	}
	/*check for multiple years*/
	for (int y = _Year-1; y > 2008; y--)
	{
		for (int m = 12; m > 0; m--)
		{
			for (int d = 31; d > 0; d--)
			{
				tmp = strtodate(y, m, d);
				if (_data.find(tmp) != _data.end())
					return (_data[tmp]);
			}
		}
	}
	return "";
}

/*get the btc price, multiply by quant and print it*/
void BitcoinExchange::execute(void)
{
	/*get the value in the map*/
	std::string ValueFromMap = getValueFromMap(_Year, _Month, _Day);
	try
	{
		if (ValueFromMap == "")
			throw BTCExceptions::InvalidDate();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return ;
	}
	/*multiply price by quantity*/
	float FinalValueFloat = std::atof(ValueFromMap.c_str()) * _ValueFloat;
	/*To string for decimal precision in cout*/
	std::string FinalValueStr = ToString<float>(FinalValueFloat);
	if (FinalValueStr.find(".") != std::string::npos)
		FinalValueStr =  FinalValueStr.substr(0, FinalValueStr.find(".") + 4);//round to avoid scienfic notation
	/*Print result*/
	std::cout << _DateStr << " => " << _ValueFloat << " = " << FinalValueStr << std::endl;
}

/*load the file specified as arg*/
void BitcoinExchange::loadFile(char *filename)
{
	std::string line;
	std::ifstream file(filename);
	if (!file.is_open())
		throw BTCExceptions::ReadExcept();
	/*check file 'header'*/
	getline(file, line);
	if (line != "date | value")
		throw BTCExceptions::FormatExcept();
	// /*check each lines*/
	while (getline(file, line))
		if (checkFileLine(line))
			execute();
	file.close();
}

/*check for bad input in the file line*/
bool fileBadInput(std::string &line)
{
	try
	{
		if (line.size() < 14)
			throw BTCExceptions::BadInput();
		if (line.find(" | ") == std::string::npos)
			throw BTCExceptions::BadInput();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << line << "\033[0m" << std::endl;
		return false;
	}
	return (true);
}

/*check the date format and the date validity*/
void BitcoinExchange::checkDate()
{
	//check date format
	if (!isDateFormat(_DateStr))
		throw BTCExceptions::DateFormat();
	//check if date exists
	std::string tmp = _DateStr.substr(0, 4);
	_Year = FromString<int>(tmp);
	tmp = _DateStr.substr(5, 2);
	_Month = FromString<int>(tmp);
	tmp = _DateStr.substr(8, 2);
	_Day = FromString<int>(tmp);
	if (!isDateValid(_Year, _Month, _Day))
		throw BTCExceptions::InvalidDate();
}

/*check the value format and validity*/
void BitcoinExchange::checkValue()
{
	//check the value format
	if (!isValueFormat(_ValueStr))
		throw BTCExceptions::ValueFormat();
	//check if value is in range;
	this->_ValueFloat = FromString<float>(_ValueStr);
	if (_ValueFloat < 0)
		throw BTCExceptions::NegNumber();
	if (_ValueFloat > 1000)
		throw BTCExceptions::LargeNumber();
}


/*process each lines of the file*/
bool	BitcoinExchange::checkFileLine(std::string &line)
{
	//precheck for bad input
	if (!fileBadInput(line))
		return (false);
	this->_DateStr = line.substr(0, 10);
	this->_ValueStr = line.substr(13);
	try
	{
		checkDate();
		checkValue();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
		return (false);
	}
	return (true);
}

BitcoinExchange::BitcoinExchange(int ac, char **av) : _DateStr(""), _ValueStr(""), _ValueFloat(0)
{
	/*open and read file*/
	if (ac != 2)
		throw BTCExceptions::OpenExcept();
	/*csv*/
	loadCSV();
	/*file*/
	loadFile(av[1]);
}

/*==========EXCEPTIONS==========*/
const char *BTCExceptions::OpenExcept::what() const throw() { return ("\033[1;31mError : could not open file.\033[0m"); }
const char *BTCExceptions::ValueFormat::what() const throw() { return ("\033[1;31mError : bad value format (digits and only 1 point for decimals).\033[0m"); }
const char *BTCExceptions::DateFormat::what() const throw() { return ("\033[1;31mError : bad date format (YYYY-MM-DD)\033[0m"); }
const char *BTCExceptions::FormatExcept::what() const throw() { return ("\033[1;31mError : invalid file formatting\033[0m"); }
const char *BTCExceptions::BadInput::what() const throw() { return ("\033[1;31mError : bad input => "); }
const char *BTCExceptions::ReadExcept::what() const throw() { return ("\033[1;31mError : could not read the file passed as argument\033[0m"); }
const char *BTCExceptions::NegNumber::what() const throw() { return ("\033[1;31mError : not a positive number.\033[0m"); }
const char *BTCExceptions::LargeNumber::what() const throw() { return ("\033[1;31mError : too large number.\033[0m"); }
const char *BTCExceptions::InvalidDate::what() const throw() { return ("\033[1;31mError : Invalid Date. (either doesn't exist or out of our range)\033[0m"); }
const char *BTCExceptions::CSVExcept::what() const throw() { return ("\033[1;31mError : Error In CSV file.\033[0m"); }

/*==========CANON==========*/

BitcoinExchange::~BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(BitcoinExchange const &src){*this = src;}
BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const &rhs){(void)rhs;return *this;}
BTCExceptions& BTCExceptions::operator=(BTCExceptions const &rhs){(void)rhs;return *this;};
