/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:53:52 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/16 14:03:06 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "[DOG] - ";
	std::cout << "Dog constructor called" << std::endl;
	this->_type = "Dog";
}

Dog::Dog(Dog &src)
{
	std::cout << "[DOG] - ";
	std::cout << "Dog copy constructor called" << std::endl;
	*this = src;
}

Dog::~Dog()
{
	std::cout << "[DOG] - ";
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(Dog const &src)
{
	std::cout << "[DOG] - ";
	std::cout << "Dog operator= called" << std::endl;
	this->_type = src._type;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "[DOG] - ";
	std::cout << "makeSound called" << std::endl;
	std::cout << "BARK BARK BARK" << std::endl;
}