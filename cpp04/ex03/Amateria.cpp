/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Amateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:51:01 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/18 20:29:07 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

/*Constructor*/
AMateria::AMateria(std::string const &type)
{
	announce(__FUNCTION__, __CLASS_NAME__);
	this->_type = type;
}

/*Returns the materia type*/
std::string const &AMateria::getType() const
{
	// announce(__FUNCTION__, __CLASS_NAME__);
	return (this->_type);
}

/*Use definition for Ice and Cure, never called.*/
void AMateria::use(ICharacter &target)
{
	announce(__FUNCTION__, __CLASS_NAME__);
	(void)target;

}

/*Operator= never called (abstract class)*/
AMateria &AMateria::operator=(AMateria const &src)
{
	announce(__FUNCTION__, __CLASS_NAME__);
	this->_type = src.getType();
	return (*this);
}
/*Destructor*/
AMateria::~AMateria()
{
	announce(__FUNCTION__, __CLASS_NAME__);
}