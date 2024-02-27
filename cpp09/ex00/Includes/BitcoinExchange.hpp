/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:27:04 by lboulang          #+#    #+#             */
/*   Updated: 2024/02/27 16:40:57 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <climits>
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>

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
		BitcoinExchange(){};
		BitcoinExchange(int ac, char **av);
		~BitcoinExchange(){};
		void parse(void){};
		void execute(void);
		bool check_line(std::string &line);
		void load_csv(std::ifstream &data);
		std::string getval(int convertedYear, int convertedMonth, int convertedDay);
		
	private:
		std::string _fullDate;
		std::string _Value;
		double 		_ValueDouble;
		std::map<std::string, std::string> _data;
};

#endif