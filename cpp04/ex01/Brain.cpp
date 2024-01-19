/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:16:20 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/19 17:06:08 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "[BRAIN] - ";
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(Brain const &src)
{
	std::cout << "[BRAIN] - ";
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = src._ideas[i];
}

Brain::~Brain()
{
	std::cout << "[BRAIN] - ";
	std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(Brain const &src)
{
	std::cout << "[BRAIN] - ";
	std::cout << "Brain operator= called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = src._ideas[i];
	return (*this);
}

void Brain::showIdeas(void)
{
	std::cout << "[BRAIN] - ";
	std::cout << "Brain showIdeas called" << std::endl;
	for (int i = 0; i < 100; i++)
		std::cout << "idea " << i << " : " << this->_ideas[i] << std::endl;
}

void Brain::setIdeas(int i, std::string idea)
{
	// std::cout << "[BRAIN] - ";
	// std::cout << "Brain setIdeas called" << std::endl;
	this->_ideas[i] = idea;
}