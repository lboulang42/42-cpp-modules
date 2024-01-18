/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Amateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:51:01 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/17 22:35:17 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

/*Constructor*/
AMateria::AMateria(std::string const &type)
{
	// std::cout << "[Amateria] -" ;
	// std::cout << " constructor called" << std::endl;
	this->_type = type;
}

/*Returns the materia type*/
std::string const &AMateria::getType() const
{
	// std::cout << "[Amateria] -" ;
	// std::cout << " getType called" << std::endl;
	return (this->_type);
}

/*Use definition for Ice and Cure, never called.*/
void AMateria::use(ICharacter &target)
{
	(void)target;
	// std::cout << "[Amateria] -" ;
	// std::cout << " use called" << std::endl;
}


AMateria & AMateria::operator=(AMateria const &src)
{
	// std::cout << "[Amateria] -" ;
	// std::cout << " operator= called" << std::endl;
	this->_type = src._type;
	return (*this);

}
/*Destructor*/
AMateria::~AMateria()
{
	// std::cout << "[Amateria] -" ;
	// std::cout << " destructor called" << std::endl;
}