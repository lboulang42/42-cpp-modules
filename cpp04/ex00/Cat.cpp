/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:53:52 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/16 14:03:06 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "[CAT] - ";
    std::cout << "Cat constructor called" << std::endl;
    this->_type = "Cat";
}

Cat::Cat(Cat &src)
{
    std::cout << "[CAT] - ";
    std::cout << "Cat copy constructor called" << std::endl;
    *this = src;
}

Cat::~Cat()
{
    std::cout << "[CAT] - ";
    std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(Cat const &src)
{
    std::cout << "[CAT] - ";
    std::cout << "Cat operator= called" << std::endl;
    this->_type = src._type;
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << "[CAT] - ";
    std::cout << "makeSound called" << std::endl;
    std::cout << "MIAOU MIAOU" << std::endl;
}