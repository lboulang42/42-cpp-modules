/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:53:52 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/16 14:03:06 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "[WRONG CAT] - ";
	std::cout << "WrongCat constructor called" << std::endl;
	this->_type = "WrongCat";
}

WrongCat::WrongCat(WrongCat &src)
{
	std::cout << "[WRONG CAT] - ";
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = src;
}

WrongCat::~WrongCat()
{
	std::cout << "[WRONG CAT] - ";
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const &src)
{
	std::cout << "[WRONG CAT] - ";
	std::cout << "WrongCat operator= called" << std::endl;
	this->_type = src._type;
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "[WRONG CAT] - ";
	std::cout << "makeSound called" << std::endl;
	std::cout << "GRAOUUUUUUUU" << std::endl;
}