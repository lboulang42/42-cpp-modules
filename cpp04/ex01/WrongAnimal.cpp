/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:36:22 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/13 17:31:15 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/*Constructeur par defaut*/
WrongAnimal::WrongAnimal()
{
	std::cout << "[NEW WrongAnimal IN TOWN] - ";
	std::cout << "WrongAnimal constructor called" << std::endl; 
	this->_type = "WrongAnimal";
}

/*Constructeur de recopie*/
WrongAnimal::WrongAnimal(WrongAnimal const &src)
{
	std::cout << "[NEW WrongAnimal IN TOWN] - ";
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

/*Destructeur*/
WrongAnimal::~WrongAnimal()
{
	std::cout << "[NEW WrongAnimal IN TOWN] - ";
	std::cout << "WrongAnimal destructor called " << std::endl;
}

/*Operator =*/
WrongAnimal &WrongAnimal::operator=(WrongAnimal const &rhs)
{
	std::cout << "[NEW WrongAnimal IN TOWN] - ";
	std::cout << "WrongAnimal operator= called" << std::endl;
	this->_type = rhs._type;
	return (*this);
}

std::string WrongAnimal::getType(void) const
{
	return (this->_type);
}

void WrongAnimal::makeSound(void) const
{
	if (this->_type == "WrongCat")
		return ((void)(std::cout << "WAIM WAIM WAIM" << std::endl));
	if (this->_type == "WrongAnimal")
		return ((void)(std::cout << "CA FAIT QUOI COMME BRUIT UN WRONG ANIMAL ??" << std::endl));

}
