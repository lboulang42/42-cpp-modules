/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:36:22 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/12 18:49:45 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


/*Constructeur par defaut*/
ClapTrap::ClapTrap(std::string name)
{
	std::cout << "Default constructor Name called" << std::endl;
    this->_name = name;
    this->_hitpoints = 10;//health points
    this->_energyPoints = 10;//energy points
    this->_attackDamage = 0;//attack damage
}

/*When ClapTrack attacks, it causes its target to lose <attack damage> hit points.*/
/* Attacking and repairing cost 1 energy point each. */
void ClapTrap::attack(std::string const & target)
{
    if (this->_energyPoints < 1)
        return ((void)(std::cout << "Not enough energy points" << std::endl));
    std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
    this->_energyPoints -= 1;
}


void ClapTrap::takeDamage(unsigned int amount)
{
    this->_hitpoints -= amount;
}

/*When ClapTrap repairs itself, it gets <amount> hit points back.*/
/* Attacking and repairing cost 1 energy point each. */
void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_energyPoints < 1)
        return ((void)(std::cout << "Not enough energy points" << std::endl));
    this->_hitpoints += amount;
    this->_energyPoints -= 1;
}


/*Constructeur de recopie*/
ClapTrap::ClapTrap(ClapTrap const &src)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

/*Destructeur*/
ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called" << std::endl;
}

/*Operator =*/
ClapTrap &ClapTrap::operator=(ClapTrap const &rhs)
{
    // std::cout << "Copy assignment operator called" << std::endl;
    this->_name = rhs._name;
    this->_hitpoints = rhs._hitpoints;
    this->_energyPoints = rhs._energyPoints;
    this->_attackDamage = rhs._attackDamage;
    return (*this);
}
