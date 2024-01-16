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
    this->_brain = new Brain();
}

Cat::Cat(Cat const &src)
{
    std::cout << "[CAT] - ";
    std::cout << "Cat copy constructor called" << std::endl;
    this->_type = src._type;
    this->_brain = new Brain(*src._brain);
}

Cat::~Cat()
{
    std::cout << "[CAT] - ";
    std::cout << "Cat destructor called" << std::endl;
    delete this->_brain;
}

Cat &Cat::operator=(Cat const &src)
{
    std::cout << "[CAT] - ";
    std::cout << "Cat operator= called" << std::endl;
    this->_type = src._type;
    this->_brain = new Brain(*src._brain); // Fix: Call the copy constructor of the Brain class
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << "[CAT] - ";
    std::cout << "makeSound called" << std::endl;
    std::cout << "MIAOU MIAOU" << std::endl;
}

void Cat::setIdeas(int i, std::string idea)
{
    this->_brain->setIdeas(i, idea);
}

void Cat::showIdeas(void)
{
   this->_brain->showIdeas();
}