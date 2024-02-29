/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:27:04 by lboulang          #+#    #+#             */
/*   Updated: 2024/02/29 13:21:44 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <climits>
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <math.h>

template<typename T>
T FromString(const std::string& str)
{
	std::istringstream is(str);
	T t;
	is >> t;
	return t;
}

template<typename T>
std::string ToString(const T& t)
{
	std::ostringstream os;
	os << t;
	return os.str();
}

class BTCExceptions
{
	public:
		class OpenExcept : public std::exception { public: virtual const char* what() const throw(); };
		class ValueFormat : public std::exception { public: virtual const char* what() const throw(); };
		class DateFormat : public std::exception { public: virtual const char* what() const throw(); };
		class FormatExcept : public std::exception { public: virtual const char* what() const throw(); };
		class BadInput : public std::exception { public: virtual const char* what() const throw(); };
		class ReadExcept : public std::exception { public: virtual const char* what() const throw(); };
		class NegNumber : public std::exception { public: virtual const char* what() const throw(); };
		class LargeNumber : public std::exception { public: virtual const char* what() const throw(); };
		class InvalidDate : public std::exception { public: virtual const char* what() const throw(); };
		class CSVExcept : public std::exception { public: virtual const char* what() const throw(); };
	private : 
		BTCExceptions();
		virtual ~BTCExceptions()=0;
		BTCExceptions(BTCExceptions const &src);
		BTCExceptions&operator=(BTCExceptions const &rhs);
};

class BitcoinExchange
{
	public:
		BitcoinExchange(int ac, char **av);
		~BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &src);
		BitcoinExchange&operator=(BitcoinExchange const &rhs);

		void execute(void);
		bool checkFileLine(std::string &line);
		void loadCSV(void);
		void loadFile(char *filename);
		void checkDate(void);
		void checkValue(void);
		std::string getValueFromMap(int convertedYear, int convertedMonth, int convertedDay);
		
	private:
		BitcoinExchange();
		std::string _DateStr;
		std::string _ValueStr;
		float		_ValueFloat;
		std::map<std::string, std::string> _data;
		int _Year, _Month, _Day;
};

#endif
