/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:54:41 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/17 22:37:21 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    // std::cout << "[Ice] -" ;
    // std::cout << " constructor called" << std::endl;
}

Ice::Ice(Ice const &src) : AMateria(src)
{
    // std::cout << "[Ice] -" ;
    // std::cout << " copy constructor called" << std::endl;
    *this = src;
}

Ice::~Ice()
{
    // std::cout << "[Ice] -" ;
    // std::cout << " destructor called" << std::endl;
}

Ice &Ice::operator=(Ice const &rhs)
{
    // std::cout << "[Ice] -" ;
    // std::cout << " operator= called" << std::endl;
    this->_type = rhs._type;
    return (*this);
}

AMateria *Ice::clone() const
{
    // std::cout << "[Ice] -" ;
    // std::cout << " clone called" << std::endl;
    return (new Ice(*this));
}

void Ice::use(ICharacter &target)
{
    // std::cout << "[Ice] -" ;
    // std::cout << " use called" << std::endl;
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}