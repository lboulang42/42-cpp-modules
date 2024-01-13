/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:36:22 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/13 17:05:54 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"


/*Constructeur par defaut*/
Dog::Dog() : Animal()
{
    std::cout << "[BARK BARK BARK] - ";
    std::cout << "Dog constructor called" << std::endl;
    this->_type = "Dog";
}

/*Constructeur de recopie*/
Dog::Dog(Dog const &src)
{
    std::cout << "[BARK BARK BARK] - ";
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

/*Destructeur*/
Dog::~Dog()
{
    std::cout << "[BARK BARK BARK] - ";
    std::cout << "Dog destructor called " << std::endl;
}

/*Operator =*/
Dog &Dog::operator=(Dog const &rhs)
{
    std::cout << "[BARK BARK BARK] - ";
    std::cout << "Dog operator= called" << std::endl;
    this->_type = rhs._type;
    return (*this);
}