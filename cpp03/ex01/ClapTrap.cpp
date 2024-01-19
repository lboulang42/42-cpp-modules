/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:36:22 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/19 16:29:31 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/*Constructeur par defaut*/
ClapTrap::ClapTrap(std::string name)
{
    std::cout << "[CLAPTRAP METHOD] - ";
	std::cout << "ClapTrap constructor Name called with name :" << name << std::endl;
	this->_name = name;
	this->_hitpoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

/*Constructeur de recopie*/
ClapTrap::ClapTrap(ClapTrap const &src)
{
    std::cout << "[CLAPTRAP METHOD] - ";
	std::cout << "Copy constructor called" << std::endl;
    this->_name = src._name;
    this->_hitpoints = src._hitpoints;
    this->_energyPoints = src._energyPoints;
    this->_attackDamage = src._attackDamage;
}

/*Destructeur*/
ClapTrap::~ClapTrap()
{
    std::cout << "[CLAPTRAP METHOD] - ";
	std::cout << "ClapTrap " << this->_name << " destructor called " << std::endl;
}

/*Operator =*/
ClapTrap &ClapTrap::operator=(ClapTrap const &rhs)
{
    std::cout << "[CLAPTRAP METHOD] - ";
	std::cout << "ClapTrap operator= called" << std::endl;
	this->_name = rhs._name;
	this->_hitpoints = rhs._hitpoints;
	this->_energyPoints = rhs._energyPoints;
	this->_attackDamage = rhs._attackDamage;
	return (*this);
}

/*When ClapTrack attacks, it causes its target to lose <attack damage> hit points.*/
/* Attacking and repairing cost 1 energy point each. */
void ClapTrap::attack(std::string const & target)
{
    std::cout << "[CLAPTRAP METHOD] - ";
	if (this->_hitpoints < 1)
		return ((void)(std::cout << "ClapTrap " << this->_name << " Is Dead (0 hit points)!" << std::endl));
	if (this->_energyPoints < 1)
		return ((void)(std::cout << "ClapTrap " << this->_name << " Not enough energy points to attack!" << std::endl));
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoints -= 1;

}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "[CLAPTRAP METHOD] - ";
	if (this->_hitpoints < 1)
		return ((void)(std::cout << "Stop Attacking ClapTrap " << this->_name << " its already dead! :(" << std::endl));
	std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
	this->_hitpoints -= amount;
}

/*When ClapTrap repairs itself, it gets <amount> hit points back.*/
/* Attacking and repairing cost 1 energy point each. */
void ClapTrap::beRepaired(unsigned int amount)
{
    std::cout << "[CLAPTRAP METHOD] - ";
	if (this->_hitpoints < 1)
		return ((void)(std::cout << "ClapTrap " << this->_name << " Is Dead (0 hit points)!" << std::endl));
	if (this->_energyPoints < 1)
		return ((void)(std::cout << "ClapTrap " << this->_name << " Not enough energy points to be repaired!" << std::endl));
	this->_hitpoints += amount;
	this->_energyPoints -= 1;
	std::cout << "ClapTrap " << this->_name << " repairs itself, it gets " << amount << " hit points back!" << std::endl;
}
