/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:52:42 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/13 16:11:46 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "[SCAVTRAP METHOD] - ";
	std::cout << "ScavTrap constructor called" << std::endl;
	this->_hitpoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_name = name;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "[SCAVTRAP METHOD] - ";
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src)
{
	std::cout << "[SCAVTRAP METHOD] - ";
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = src;
}

void ScavTrap::attack(const std::string &target)
{
	std::cout << "[SCAVTRAP METHOD] - ";
	if (this->_hitpoints < 1)
		return ((void)(std::cout << "ScavTrap " << this->_name << " Is Dead (0 hit points)!" << std::endl));
	if (this->_energyPoints < 1)
		return ((void)(std::cout << "ScavTrap " << this->_name << " Not enough energy points to attack!" << std::endl));
	std::cout << "ScavTrap " << this->_name << " attack " << target << " causing " << this->_attackDamage << " points of damage!" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs)
{
	std::cout << "[SCAVTRAP METHOD] - ";
	std::cout << "ScavTrap operator= called" << std::endl;
	this->_name = rhs._name;
	this->_hitpoints = rhs._hitpoints;
	this->_energyPoints = rhs._energyPoints;
	this->_attackDamage = rhs._attackDamage;
	return (*this);
}

void ScavTrap::guardGet(void)
{
	std::cout << "[SCAVTRAP METHOD] - ";
	if (this->_hitpoints < 1)
		return ((void)(std::cout << "ScavTrap " << this->_name << " Is Dead (0 hit points)!" << std::endl));
	if (this->_energyPoints < 1)
		return ((void)(std::cout << "ScavTrap " << this->_name << " Not enough energy points to go gate keeper mode!" << std::endl));
	std::cout << "ScavTrap " << this->_name << " has entered in Gate keeper mode" << std::endl; 
}
