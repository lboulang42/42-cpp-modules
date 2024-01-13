/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:36:22 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/13 17:26:59 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"


/*Constructeur par defaut*/
Cat::Cat() : Animal()
{
    std::cout << "[MIAW MIAW] - ";
    std::cout << "Cat constructor called" << std::endl;
    this->_type = "Cat";
}

/*Constructeur de recopie*/
Cat::Cat(Cat const &src) : Animal(src)
{
    std::cout << "[MIAW MIAW] - ";
	std::cout << "Cat Copy constructor called" << std::endl;
	*this = src;
}

/*Destructeur*/
Cat::~Cat()
{
    std::cout << "[MIAW MIAW] - ";
    std::cout << "Cat destructor called " << std::endl;
}

/*Operator =*/
Cat &Cat::operator=(Cat const &rhs)
{
    std::cout << "[MIAW MIAW] - ";
    std::cout << "Cat operator= called" << std::endl;
    this->_type = rhs._type;   
    return (*this);
}