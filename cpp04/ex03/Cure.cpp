/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:33:53 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/16 19:47:40 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

void Cure::use(ICharacter &target)
{
    std::cout << "[CURE] - ";
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

Cure::Cure() : AMateria("cure")
{
    std::cout << "[CURE] - ";
    std::cout << "Cure constructor called" << std::endl;
}

Cure::Cure(Cure const &src) : AMateria(src)
{
    std::cout << "[CURE] - ";
    std::cout << "Cure copy constructor called" << std::endl;
    *this = src;
}

Cure::~Cure()
{
    std::cout << "[CURE] - ";
    std::cout << "Cure destructor called" << std::endl;
}

Cure &Cure::operator=(Cure const &src)
{
    std::cout << "[CURE] - ";
    std::cout << "Cure operator= called" << std::endl;
    this->_type = src._type;
    return (*this);
}

AMateria *Cure::clone() const
{
    return (new Cure(*this));
}