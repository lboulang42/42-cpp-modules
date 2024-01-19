/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:33:27 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/19 20:24:13 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const &name)
{
	announce(__FUNCTION__, __CLASS_NAME__);
	this->_name = name;
	this->_inventory[0] = NULL;
	this->_inventory[1] = NULL;
	this->_inventory[2] = NULL;
	this->_inventory[3] = NULL;
	this->_throwed = NULL;
	this->_count_throwed = 0;
}

Character::Character()
{
	announce(__FUNCTION__, __CLASS_NAME__);
	this->_name = "default name";
	this->_inventory[0] = NULL;
	this->_inventory[1] = NULL;
	this->_inventory[2] = NULL;
	this->_inventory[3] = NULL;
	this->_throwed = NULL;
	this->_count_throwed = 0;
}

Character::Character(Character const &src)
{
	announce(__FUNCTION__, __CLASS_NAME__);
	this->_name = src._name;
	this->_throwed = NULL;
	for (int i = 0; i < 4; i++)
	{
		if (src._inventory[i] != NULL)
			this->_inventory[i] = src._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
	this->_count_throwed = src._count_throwed;
}

Character::~Character()
{
	announce(__FUNCTION__, __CLASS_NAME__);
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] != NULL)
		{
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
	}
	for (int i = 0; i < this->_count_throwed; i++)
	{
		if (this->_throwed[i] != NULL)
		{
			delete this->_throwed[i];
			this->_throwed[i] = NULL;
		}
	}
	if (this->_throwed)
		delete[] this->_throwed;
}

Character &Character::operator=(Character const &rhs)
{
	std::cout << "Character operator=" << std::endl;
	announce(__FUNCTION__, __CLASS_NAME__);
	if (this != &rhs)
	{
		this->_name = rhs._name;
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i])
				delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
		for (int i = 0; i < 4; i++)
			if (rhs._inventory[i] != NULL)
				this->_inventory[i] = rhs._inventory[i]->clone();
	}
	return (*this);
}

void Character::equip(AMateria *m)
{
	announce(__FUNCTION__, __CLASS_NAME__);
	if (m == NULL)
	{
		std::cout << "No Materia to equip" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			std::cout << "Materia '" << m->getType() << "' have been equiped" << std::endl;
			return ;
		}
	}
	std::cout << "Cant equip the materia " << m->getType() << " with a full inventory" << std::endl;
}

std::string const &Character::getName() const
{
	// announce(__FUNCTION__, __CLASS_NAME__);
	return (this->_name);
}

void Character::unequip(int idx)
{
	announce(__FUNCTION__, __CLASS_NAME__);
	if (idx < 0 || idx > 3)
	{
		std::cout << "Wrong index" << std::endl;
		return ;
	}
	if (this->_inventory[idx] == NULL)
	{
		std::cout << "No Materia to unequip" << std::endl;
		return ;
	}
	AMateria	**tmp = new AMateria *[this->_count_throwed + 1];
	for (int i = 0; i < this->_count_throwed; i++)
		tmp[i] = this->_throwed[i];
	if (this->_throwed)
		delete[] this->_throwed;
	tmp[this->_count_throwed++] = this->_inventory[idx];
	std::cout << "Materia '" << this->_inventory[idx]->getType() << "' have been unequiped" << std::endl;
	this->_throwed = tmp;
	this->_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	announce(__FUNCTION__, __CLASS_NAME__);
	if (idx < 0 || idx > 3)
	{
		std::cout << "Wrong index" << std::endl;
		return ;
	}
	if (this->_inventory[idx] != NULL)
		this->_inventory[idx]->use(target);
	else
		std::cout << "can't use this materia" << std::endl;
}