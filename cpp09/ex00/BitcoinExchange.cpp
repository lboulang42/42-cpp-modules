/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:26:58 by lboulang          #+#    #+#             */
/*   Updated: 2024/02/27 19:28:05 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <stdlib.h>
#include <algorithm>
#include <iostream>     // std::cout, std::fixed
#include <iomanip>      // std::setprecision
/*
parse date format
parse date valide (time)
parse value format
parse value (entre 0 et max int)

execute : 
	- create a map with date as key and value as value
	- print the map
*/

/*
$> ./btc
Error: could not open file.
$> ./btc input.txt
2011-01-03 => 3 = 0.9
2011-01-03 => 2 = 0.6
2011-01-03 => 1 = 0.3
2011-01-03 => 1.2 = 0.36
2011-01-09 => 1 = 0.32
Error: not a positive number. (2012-01-11 | -1)
Error: bad input => 2001-42-42 (2001-42-42)
2012-01-11 => 1 = 7.1
Error: too large a number. (2012-01-11 | 2147483648)
*/




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

bool isDateFormat(std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
		{
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

void BitcoinExchange::load_csv(std::ifstream &data)
{
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
}

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

std::string BitcoinExchange::getval(int convertedYear, int convertedMonth, int convertedDay)
{
	std::string tmp;

	for (int d = convertedDay-1; d > 0; d--)
	{
		tmp = strtodate(convertedYear, convertedMonth, d);
		if (_data.find(tmp) != _data.end())
			return (_data[tmp]);
	}	
	
	for (int m = convertedMonth-1; m > 0; m--)
	{
		for (int d = 31; d > 0; d--)
		{
			tmp = strtodate(convertedYear, m, d);
			if (_data.find(tmp) != _data.end())
				return (_data[tmp]);
		}
	}
	for (int y = convertedYear-1; y > 2008; y--)
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


bool	BitcoinExchange::check_line(std::string &line)
{
	//precheck for bad input
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

	this->_fullDate = line.substr(0, 10);
	this->_Value = line.substr(13);
	int convertedYear, convertedMonth, convertedDay;
	try
	{
		//check date format
		if (!isDateFormat(_fullDate))
			throw BTCExceptions::DateFormat();
		//check if date exists
		std::string tmp = _fullDate.substr(0, 4);
		convertedYear = FromString<int>(tmp);
		tmp = _fullDate.substr(5, 2);
		convertedMonth = FromString<int>(tmp);
		tmp = _fullDate.substr(8, 2);
		convertedDay = FromString<int>(tmp);
		if (!isDateValid(convertedYear, convertedMonth, convertedDay))
			throw BTCExceptions::InvalidDate();

		//check the value format
		if (!isValueFormat(_Value))
			throw BTCExceptions::ValueFormat();
		
		//check if value should be accepted
		this->_ValueDouble = FromString<double>(_Value);
		if (_ValueDouble < 0)
			throw BTCExceptions::NegNumber();
		if (_ValueDouble > 1000)
			throw BTCExceptions::LargeNumber();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
		return (false);
	}
	
	std::string valindata;
	if (_data.find(_fullDate) != _data.end())
		valindata = _data[_fullDate];
	else
	{
		valindata = getval(convertedYear, convertedMonth, convertedDay);
	}
	int lenfrac = 0;	
	if (valindata.find(".") != std::string::npos)
	{
		std::string tmp = valindata.substr(0, valindata.find("."));
		std::string frac = valindata.substr(valindata.find(".")+1);
		lenfrac = frac.length(); 
	}
	float val = std::atof(valindata.c_str());
	float val2 = static_cast<float>(_ValueDouble);
	// std::cout  << std::fixed << std::setprecision(lenfrac) << "val = " << val << " val2 = " << val2 << std::endl;
	val = val * val2;
	std::string allerfrr = ToString<float>(val);
	std::cout << _fullDate << " => " << _ValueDouble << " = " << allerfrr << std::endl;
	return (true);
}

void BitcoinExchange::execute(void)
{
}

BitcoinExchange::BitcoinExchange(int ac, char **av) : _fullDate(""), _Value(""), _ValueDouble(0)
{
	/*open and read file*/
	if (ac != 2)
		throw BTCExceptions::OpenExcept();
	std::ifstream file(av[1]);
	if (!file.is_open())
		throw BTCExceptions::ReadExcept();
	/*check file 'header'*/
	std::string line;
	getline(file, line);
	if (line != "date | value")
		throw BTCExceptions::FormatExcept();
	
	//load data.csv
	std::ifstream data("data.csv");
	if (!data.is_open())
		throw BTCExceptions::CSVExcept();
	load_csv(data);
	std::cout << "data.csv loaded" << std::endl;
	data.close();

	// /*check each lines*/
	while (getline(file, line))
	{
		if (check_line(line))
			execute();
	}
	file.close();
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
