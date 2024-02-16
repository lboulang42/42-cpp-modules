/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:06:50 by lboulang          #+#    #+#             */
/*   Updated: 2024/02/16 13:07:46 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <sstream>
# include <cstdlib>
# include <cstring>
# include <climits>

# define CHAR 0
# define INT 1
# define FLOAT 2
# define DOUBLE 3
# define IMPOSSIBLE -1

class ScalarConverter
{
	public:
		/*==========CANONICAL==========*/
		/*default constructor*/
		ScalarConverter ( void );
		/*copy constructor*/
		ScalarConverter ( ScalarConverter const &src );
		/*operator = */
		ScalarConverter &operator= (ScalarConverter const &rhs);
		/*destructor*/
		~ScalarConverter ( void );
		
		/*==========OTHER CONSTRUCTOR==========*/
		ScalarConverter ( std::string const &str );

		/*==========MEMBER FUNCTIONS==========*/
		/*Global*/
		void checkType ( void );
		
		/*Char*/
		bool isChar ( void );
		void convertChar ( void );

		/*Int*/
		bool isInt ( void );
		void convertInt ( void );

		/*Float*/
		bool isFloat ( void );
		void convertFloat ( void );

		/*Double*/
		bool isDouble ( void );
		void convertDouble ( void );
		
		/*Literals*/
		bool checkLiterals(std::string const &str);
		void printLiterals ( void );
		
		void convertImpossible ( void );
	private:
		std::string _str;
		bool		_overflow;
};

#endif
