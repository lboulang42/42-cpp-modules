/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:06:11 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/11 18:55:45 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


Fixed::Fixed(Fixed const & src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
   
}

Fixed::Fixed(void)
{
    std::cout << "Default constructor called" << std::endl;
    this->_fixedvalue = 0;
}

Fixed& Fixed::operator=(Fixed const & rhs)
{
    this->_fixedvalue = rhs.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

/*◦ Une fonction membre int getRawBits( void ) const;
qui retourne la valeur du nombre à virgule fixe sans la convertir.*/

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_fixedvalue);
}

/*
Une fonction membre void setRawBits( int const raw );
qui initialise la valeur du nombre à virgule fixe avec celle passée en paramètre
*/

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_fixedvalue = raw;
}
