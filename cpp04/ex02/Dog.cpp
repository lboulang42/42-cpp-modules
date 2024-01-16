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
    this->_brain = new Brain();
}

Dog::Dog(Dog const &src)
{
    std::cout << "[DOG] - ";
    std::cout << "Dog copy constructor called" << std::endl;
    this->_type = src._type;
    this->_brain = new Brain(*src._brain);
}

Dog::~Dog()
{
    std::cout << "[DOG] - ";
    std::cout << "Dog destructor called" << std::endl;
    delete this->_brain;
}

Dog &Dog::operator=(Dog const &src)
{
    std::cout << "[DOG] - ";
    std::cout << "Dog operator= called" << std::endl;
    this->_type = src._type;
    this->_brain = new Brain(*src._brain);
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << "[DOG] - ";
    std::cout << "makeSound called" << std::endl;
    std::cout << "BARK BARK BARK" << std::endl;
}

void Dog::setIdeas(int i, std::string idea)
{
    if (i < 100)
        this->_brain->setIdeas(i, idea);
}

void Dog::showIdeas(void)
{
   this->_brain->showIdeas();
}