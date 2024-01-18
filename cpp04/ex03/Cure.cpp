/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:54:41 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/17 17:59:43 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	announce(__FUNCTION__, __CLASS_NAME__);
}

Cure::Cure(Cure const &src) : AMateria(src)
{
	announce(__FUNCTION__, __CLASS_NAME__);
	*this = src;
}

Cure::~Cure()
{
	announce(__FUNCTION__, __CLASS_NAME__);
}

Cure &Cure::operator=(Cure const &rhs)
{
	announce(__FUNCTION__, __CLASS_NAME__);
	this->_type = rhs._type;
	return (*this);
}

AMateria *Cure::clone() const
{
	announce(__FUNCTION__, __CLASS_NAME__);
	return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
	announce(__FUNCTION__, __CLASS_NAME__);
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}