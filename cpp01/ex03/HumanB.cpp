/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 18:08:28 by lboulang          #+#    #+#             */
/*   Updated: 2023/12/31 18:33:47 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

void HumanB::attack()
{
	if (!this->weapon)
		return(	(void)(std::cout << this->name << " has no weapon" << std::endl));
	std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

HumanB::HumanB(std::string name)
{
	std::cout << "HumanB created" << std::endl;
	this->name = name;
	this->weapon = NULL;
}

HumanB::HumanB(std::string name, Weapon &weapon)
{
	std::cout << "HumanB createdwith weapon" << std::endl;
	this->name = name;
	this->weapon = &weapon;
}

HumanB::~HumanB()
{
	std::cout << "HumanB destroyed" << std::endl;
}