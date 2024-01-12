/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:06:11 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/11 19:07:53 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

/*
1 << 8 = 1*2^8 = 256
1 >> 8 = 1/2^8 = 1/256
*/

/*Constructeur par defaut*/
Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixedvalue = 0;
}

/*Constructeur de recopie*/
Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

/*Constructeur par int*/
Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedvalue = value << this->_fractionalBits;
}

/*Constructeur par float*/
Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixedvalue = roundf(value * (1 << this->_fractionalBits));
}

/*Destructor*/
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

/*Operator =*/
Fixed &Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixedvalue = rhs.getRawBits();
	return (*this);
}




/*Operator d'insertion << */
std::ostream &operator<<(std::ostream &ouputstream, Fixed const &rhs)
{
	ouputstream << rhs.toFloat();
	return (ouputstream);
}

/*Set _fixedvalue avec raw*/
void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedvalue = raw;
}

/*Retourne les bits de _fixedvalue*/
int Fixed::getRawBits(void) const
{
	return (this->_fixedvalue);
}

/*Retourne _fixedvalue converti en float*/
float Fixed::toFloat(void) const
{
	return ((float)(this->_fixedvalue) / (1 << this->_fractionalBits));
}

/*Retourne _fixedvalue converti en int*/
int Fixed::toInt(void) const
{
	/*decale de fractionalBits vers la droite (== /256)*/
	return (this->_fixedvalue >> this->_fractionalBits);
}






	
	