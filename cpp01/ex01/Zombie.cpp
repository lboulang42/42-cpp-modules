/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 18:15:26 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/10 16:18:03 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::setname(std::string name)
{
	this->name = name;
}

/*
Create a zombie, give it a name and return it so it can be used outside of the
scope of the function. (+/- like alloc)
*/
Zombie* newZombie(std::string name)
{
	// std::cout << "Using new zombie" << std::endl;
	Zombie *zomb = new Zombie;	
	zomb->setname(name);
	return (zomb);
}


void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie()
{
	std::cout << "Zombie created" << std::endl;
}

/*
Called when "delete" on zombie created using new
Called when exiting scope of zombie created on stack
*/
Zombie::~Zombie()
{
	std::cout << "Destroying Zombie named " << name << std::endl;
}
