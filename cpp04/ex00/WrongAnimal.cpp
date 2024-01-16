/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:53:52 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/16 14:15:41 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "[WRONG ANIMAL] - ";
	std::cout << "WrongAnimal constructor called" << std::endl;
	this->_type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(WrongAnimal &src)
{
	std::cout << "[WRONG ANIMAL] - ";
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = src;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "[WRONG ANIMAL] - ";
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &src)
{
	std::cout << "[WRONG ANIMAL] - ";
	std::cout << "WrongAnimal operator= called" << std::endl;
	this->_type = src._type;
	return (*this);
}

std::string WrongAnimal::getType() const
{
	std::cout << "[WRONG ANIMAL] - ";
	std::cout << "WrongAnimal getType called :" << std::endl;
	return (this->_type);   
}

void WrongAnimal::makeSound() const
{
	std::cout << "[WRONG ANIMAL] - ";
	std::cout << "makeSound called" << std::endl;
	std::cout << "bruit d'un wrong animal ?" << std::endl;
}