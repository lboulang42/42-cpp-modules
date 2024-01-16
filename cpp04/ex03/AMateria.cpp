/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:29:15 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/16 19:46:55 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const &type)
{
    std::cout << "[AMATERIA] - ";
    std::cout << "AMateria constructor called" << std::endl;
}

AMateria::AMateria(AMateria const &src)
{
    std::cout << "[AMATERIA] - ";
    std::cout << "AMateria copy constructor called" << std::endl;
    *this = src;
}

AMateria::~AMateria()
{
    std::cout << "[AMATERIA] - ";
    std::cout << "AMateria destructor called" << std::endl;
}

AMateria &AMateria::operator=(AMateria const &src)
{
    std::cout << "[AMATERIA] - ";
    std::cout << "AMateria operator= called" << std::endl;
    return (*this);
}

std::string const &AMateria::getType() const
{
    //Returns the materia type
    return (this->_type);
}

AMateria *AMateria::clone() const
{
    return ;
}

void AMateria::use(ICharacter &target)
{
    std::cout << "[AMATERIA] - ";
    std::cout << "AMateria use called" << std::endl;
}