/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:54:41 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/18 19:58:54 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	announce(__FUNCTION__, __CLASS_NAME__);
}

Ice::Ice(Ice const &src) : AMateria(src)
{
	announce(__FUNCTION__, __CLASS_NAME__);
	*this = src;
}

Ice::~Ice()
{
	announce(__FUNCTION__, __CLASS_NAME__);
}

Ice &Ice::operator=(Ice const &rhs)
{
	announce(__FUNCTION__, __CLASS_NAME__);
	this->_type = rhs._type;
	return (*this);
}

AMateria *Ice::clone() const
{
	announce(__FUNCTION__, __CLASS_NAME__);
	return (new Ice(*this));
}

void Ice::use(ICharacter &target)
{
	announce(__FUNCTION__, __CLASS_NAME__);
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}