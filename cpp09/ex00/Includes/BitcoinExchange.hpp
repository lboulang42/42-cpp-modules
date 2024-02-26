/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:27:04 by lboulang          #+#    #+#             */
/*   Updated: 2024/02/26 19:04:55 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
// #include <sstream>
#include <fstream>

class BitcoinExchange
{
	public:
		BitcoinExchange(){};
		BitcoinExchange(int ac, char **av);
		~BitcoinExchange(){};
		void parse(void){};
		void execute(void){};
		class Error : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("\033[1;31mError : Error\033[0m");
				}
		};
		class nArgs : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("\033[1;31mError : need 2 arguments\033[0m");
				}
		};
		class readFile : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("\033[1;31mError : can't read the file passed as argument\033[0m");
				}
		};
};

#endif