/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 18:15:26 by lboulang          #+#    #+#             */
/*   Updated: 2023/12/31 13:52:06 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::setname(std::string name)
{
	this->name = name;
}

void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie &Zombie::operator=(const Zombie &other)
{
	// std::cout << "Assignation operator called" << std::endl;
	this->name = other.name;
	return *this;
}

Zombie::Zombie()
{
	// std::cout << "Zombie created" << std::endl;
}

/*
Called when "delete" on zombie created using new
Called when exiting scope of zombie created on stack
*/
Zombie::~Zombie()
{
	std::cout << "Destroying Zombie named " << name << std::endl;
}

Zombie::Zombie(const Zombie &value)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = value;
}
