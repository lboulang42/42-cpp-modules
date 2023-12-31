/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 18:33:56 by lboulang          #+#    #+#             */
/*   Updated: 2023/12/31 18:34:00 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"


HumanA::~HumanA()
{
	std::cout << "HumanA destroyed" << std::endl;
}	

void HumanA::attack()
{
	std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

HumanA::HumanA(std::string name, Weapon &weapon)
{
	std::cout << "HumanA created" << std::endl;
	this->name = name;
	this->weapon = &weapon;
}

