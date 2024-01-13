/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:36:22 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/13 17:43:31 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"


/*Constructeur par defaut*/
WrongCat::WrongCat() : WrongAnimal()
{
    std::cout << "[MIAW MIAW] - ";
    std::cout << "WrongCat constructor called" << std::endl;
    this->_type = "WrongCat";
}

/*Constructeur de recopie*/
WrongCat::WrongCat(WrongCat const &src) : WrongAnimal(src)
{
    std::cout << "[MIAW MIAW] - ";
	std::cout << "WrongCat Copy constructor called" << std::endl;
	*this = src;
}

/*Destructeur*/
WrongCat::~WrongCat()
{
    std::cout << "[MIAW MIAW] - ";
    std::cout << "WrongCat destructor called " << std::endl;
}

/*Operator =*/
WrongCat &WrongCat::operator=(WrongCat const &rhs)
{
    std::cout << "[MIAW MIAW] - ";
    std::cout << "WrongCat operator= called" << std::endl;
    this->_type = rhs._type;   
    return (*this);
}