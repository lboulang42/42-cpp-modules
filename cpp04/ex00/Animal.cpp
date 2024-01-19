/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:53:52 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/19 16:57:28 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "[ANIMAL] - ";
	std::cout << "Animal constructor called" << std::endl;
	this->_type = "Animal";
}

Animal::Animal(Animal &src)
{
	std::cout << "[ANIMAL] - ";
	std::cout << "Animal copy constructor called" << std::endl;
	*this = src;
}

Animal::~Animal()
{
	std::cout << "[ANIMAL] - ";
	std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(Animal const &src)
{
	std::cout << "[ANIMAL] - ";
	std::cout << "Animal operator= called" << std::endl;
	this->_type = src._type;
	return (*this);
}

std::string Animal::getType() const
{
	std::cout << "[ANIMAL] - ";
	std::cout << "Animal getType called :" << std::endl;
	return (this->_type);   
}

void Animal::makeSound() const
{
	std::cout << "[ANIMAL] - ";
	std::cout << "makeSound called" << std::endl;
	std::cout << "? bruit d'animal je suppose" << std::endl;
}