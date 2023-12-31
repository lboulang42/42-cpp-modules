/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 18:00:34 by lboulang          #+#    #+#             */
/*   Updated: 2023/12/31 18:07:58 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

void Weapon::setType(std::string type)
{
	this->type = type;
}

const std::string& Weapon::getType()
{
	return (this->type);
}

Weapon::Weapon()
{
	std::cout << "Weapon Created" << std::endl;
}

Weapon::Weapon(std::string type)
{
	this->type = type;
	std::cout << "Weapon Created" << std::endl;
}

Weapon::~Weapon()
{
	std::cout << "Weapon destroyed" << std::endl;
}