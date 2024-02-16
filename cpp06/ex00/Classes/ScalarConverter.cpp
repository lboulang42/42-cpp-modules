/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:22:15 by mmourdal          #+#    #+#             */
/*   Updated: 2024/02/16 13:30:48 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/*==========CANONICAL==========*/
/*default constructor*/
ScalarConverter::ScalarConverter ()
{
	std::cout << "[ScalarConverter] - ";
	std::cout << "Default constructor called" << std::endl;
}

/*copy constructor*/
ScalarConverter::ScalarConverter ( ScalarConverter const &src )
{
	std::cout << "[ScalarConverter] - ";
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

/*operator = */
ScalarConverter &ScalarConverter::operator= (ScalarConverter const &rhs)
{
	std::cout << "[ScalarConverter] - ";
	std::cout << "Assignation operator called" << std::endl;
	if (this != &rhs)
	{
		this->_str = rhs._str;
		this->_overflow = rhs._overflow;
	}
	return (*this);
}

/*destructor*/
ScalarConverter::~ScalarConverter ( void )
{
	std::cout << "[ScalarConverter] - ";
	std::cout << "Destructor called" << std::endl;
}

/*==========OTHER CONSTRUCTOR==========*/
ScalarConverter::ScalarConverter ( std::string const &str )
{
	std::cout << "[ScalarConverter] - ";
	std::cout << "Constructor with string called" << std::endl;
	
	this->_str = str;
	this->_overflow = false;
	if (checkLiterals(str))
		return  ; 
	checkType();
}

/*==========MEMBER FUNCTIONS==========*/

/*Global*/
void ScalarConverter::checkType ( void )
{
	if (isInt())
		return ((void)(this->convertInt()));
	if (isDouble())
		return ((void)(this->convertDouble()));
	if (isChar())
		return ((void)(this->convertChar()));
	if (isFloat())
		return ((void)(this->convertFloat()));
	return ((void)(this->convertImpossible()));	
}

/*Char*/
bool ScalarConverter::isChar ( void )
{
	if (this->_str.size() == 1)
		return true;
	return false;
}

void ScalarConverter::convertChar ( void )
{
	char converted_char = this->_str[0];
	int converted_int = static_cast<int>(converted_char);
	float converted_float = static_cast<float>(converted_char);
	double converted_double = static_cast<double>(converted_char);

	std::cout << "char : '" << converted_char << "'" << std::endl;
	std::cout << "int : " << converted_int << std::endl;
	std::cout << "float : " << std::fixed << std::setprecision(1) << converted_float << "f" << std::endl;
	std::cout << "double : " << std::fixed << std::setprecision(1) << converted_double << std::endl;
}

/*Int*/
bool ScalarConverter::isInt ( void )
{
    char *string_end;
	long converted = std::strtol(this->_str.c_str(), &string_end, 10);
	
	if (converted < INT_MIN || converted > INT_MAX)
		this->_overflow = true;
	if (*string_end == '\0' && this->_str.size() > 0)
		return true;
	return false;
}

void ScalarConverter::convertInt ( void )
{
	double converted_int = std::atol(this->_str.c_str());
	char converted_char = static_cast<char>(converted_int);
	float converted_float = static_cast<float>(converted_int);
	double converted_double = static_cast<double>(converted_int);

	std::cout << "char : ";
	if (std::isprint(converted_char))
		std::cout << "'" << converted_char << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;

	if (this->_overflow == false)
		std::cout << "int : " << static_cast<int>(converted_int) << std::endl;
	else
		std::cout << "int : impossible" << std::endl;
	std::cout << "float : " << std::fixed << std::setprecision(1) << converted_float << "f" << std::endl;
	std::cout << "double : " << std::fixed << std::setprecision(1) << converted_double << std::endl;
}

/*Float*/
bool ScalarConverter::isFloat ( void )
{
	int start = 0;
	const char *point = std::strchr(this->_str.c_str(), '.');
	size_t pos = this->_str.find('.');
	
	if (this->_str[0] == '+' || this->_str[0] == '-')
		start = 1;

	if (point == NULL && this->_str.size() > 1 && std::isdigit(this->_str[start]) && this->_str[this->_str.size() - 1] == 'f')
		return true;
	if (point != NULL && this->_str.size() > 1 && std::isdigit(this->_str[start]) && this->_str[this->_str.size() - 1] == 'f')
	{
		if (std::isdigit(*(point + 1)) && this->_str.find_first_not_of("0123456789f", pos + 1) == std::string::npos)
			return true;
		else
			return false;
	}
	return false;
}

void ScalarConverter::convertFloat ( void )
{
	float converted_float = std::atof(this->_str.c_str());
	char converted_char = static_cast<char>(converted_float);
	int converted_int = static_cast<int>(converted_float);
	double converted_double = static_cast<double>(converted_float);

	std::cout << "char : ";
	if (std::isprint(converted_char))
		std::cout << "'" << converted_char << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << "int : ";
	if (this->_overflow == false)
		std::cout << converted_int << std::endl;
	else
		std::cout << "impossible" << std::endl;
	std::cout << "float : " << std::fixed << std::setprecision(1) << converted_float << "f" << std::endl;
	std::cout << "double : " << std::fixed << std::setprecision(1) << converted_double << std::endl;
}

/*Double*/
bool ScalarConverter::isDouble ( void )
{
	char* string_end;
	const char *point = std::strchr(this->_str.c_str(), '.');
	int start = (this->_str[0] == '+' || this->_str[0] == '-') ? 1 : 0;

	std::strtod(this->_str.c_str(), &string_end);
    if (*string_end == '\0' && point != NULL && std::isdigit(this->_str[start]))
		if (point != NULL && std::isdigit(*(point + 1)) && this->_str.size() > 1)
			return true;
	return false;
}

void ScalarConverter::convertDouble ( void )
{
	double converted_double = std::atof(this->_str.c_str());
	char converted_char = static_cast<char>(converted_double);
	int converted_int = static_cast<int>(converted_double);
	float converted_float = static_cast<float>(converted_double);

	std::cout << "char : ";
	if (converted_double >= 0 && converted_double <= 127)
		std::cout << "'" << converted_char << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << "int : ";
	if (this->_overflow == false)
		std::cout << converted_int << std::endl;
	else
		std::cout << "impossible" << std::endl;
	std::cout << "float : " << std::fixed << std::setprecision(1) << converted_float << "f" << std::endl;
	std::cout << "double : " << std::fixed << std::setprecision(1) << converted_double << std::endl;
}

/*Literals*/
bool ScalarConverter::checkLiterals(std::string const &str)
{
	if (str == "nanf" || str == "nan" || str == "inff" || str == "inf" || str == "+inff" || str == "+inf" || str == "-inff" || str == "-inf")
		return ((void)(this->printLiterals()), (true));
	return false;
}

void ScalarConverter::printLiterals ( void )
{
	std::cout << "char : impossible"<< std::endl;
	std::cout << "int : impossible"<< std::endl;
	if (this->_str == "nanf" || this->_str == "nan")
	{
		std::cout << "float : nanf" << std::endl;
		std::cout << "double : nan" << std::endl;
	}
	else if (this->_str == "inff" || this->_str == "inf")
	{
		std::cout << "float : inff" << std::endl;
		std::cout << "double : inf" << std::endl;
	}
	else if (this->_str == "+inff" || this->_str == "+inf")
	{
		std::cout << "float : +inff" << std::endl;
		std::cout << "double : +inf" << std::endl;
	}
	else if (this->_str == "-inff" || this->_str == "-inf")
	{
		std::cout << "float : -inff" << std::endl;
		std::cout << "double : -inf" << std::endl;
	}
}

void ScalarConverter::convertImpossible ( void )
{
	std::cout << "char : impossible" << std::endl;
	std::cout << "int : impossible" << std::endl;
	std::cout << "float : impossible" << std::endl;
	std::cout << "double : impossible" << std::endl;
}
