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
    // std::cout << "[Cure] -" ;
    // std::cout << " constructor called" << std::endl;

}

Cure::Cure(Cure const &src) : AMateria(src)
{
    // std::cout << "[Cure] -" ;
    // std::cout << " copy constructor called" << std::endl;
    *this = src;
}

Cure::~Cure()
{
    // std::cout << "[Cure] -" ;
    // std::cout << " destructor called" << std::endl;
}

Cure &Cure::operator=(Cure const &rhs)
{
    // std::cout << "[Cure] -" ;
    // std::cout << " operator= called" << std::endl;
    this->_type = rhs._type;
    return (*this);
}

AMateria *Cure::clone() const
{
    // std::cout << "[Cure] -" ;
    // std::cout << " clone called" << std::endl;
    return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
    // std::cout << "[Cure] -" ;
    // std::cout << " use called" << std::endl;
    std::cout << "* shoots an Cure bolt at " << target.getName() << " *" << std::endl;
}