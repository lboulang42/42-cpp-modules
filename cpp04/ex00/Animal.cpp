/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:36:22 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/13 17:31:15 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/*Constructeur par defaut*/
Animal::Animal()
{
	std::cout << "[NEW ANIMAL IN TOWN] - ";
	std::cout << "Animal constructor called" << std::endl;
}

/*Constructeur de recopie*/
Animal::Animal(Animal const &src)
{
	std::cout << "[NEW ANIMAL IN TOWN] - ";
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

/*Destructeur*/
Animal::~Animal()
{
	std::cout << "[NEW ANIMAL IN TOWN] - ";
	std::cout << "Animal destructor called " << std::endl;
}

/*Operator =*/
Animal &Animal::operator=(Animal const &rhs)
{
	std::cout << "[NEW ANIMAL IN TOWN] - ";
	std::cout << "Animal operator= called" << std::endl;
	this->_type = rhs._type;
	return (*this);
}

std::string Animal::getType(void) const
{
	return (this->_type);
}

void Animal::makeSound(void) const
{
	if (this->_type == "Dog")
		return ((void)(std::cout << "BARK BARK BARK" << std::endl));
	if (this->_type == "Cat")
		return ((void)(std::cout << "MIAW MIAW" << std::endl));
	std::cout << "? wtf does not defined animal sound like ?" << std::endl;
}
