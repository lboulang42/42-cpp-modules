/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:02:39 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/19 16:33:31 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "[FRAGTRAP METHOD] - ";
    std::cout << "FragTrap constructor called" << std::endl;
    this->_hitpoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    this->_name = name;
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src)
{
    std::cout << "[FRAGTRAP METHOD] - ";
    std::cout << "FragTrap copy constructor called" << std::endl;
    this->_hitpoints = src._hitpoints;
    this->_energyPoints = src._energyPoints;
    this->_attackDamage = src._attackDamage;
    this->_name = src._name;
    
}

FragTrap::~FragTrap(void)
{
    std::cout << "[FRAGTRAP METHOD] - ";
    std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &rhs)
{
    std::cout << "[FRAGTRAP METHOD] - ";
    std::cout << "FragTrap operator= called" << std::endl;
    this->_name = rhs._name;
    this->_hitpoints = rhs._hitpoints;
    this->_energyPoints = rhs._energyPoints;
    this->_attackDamage = rhs._attackDamage;
    return (*this);
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "[FRAGTRAP METHOD] - ";
    if (this->_hitpoints < 1)
        return ((void)(std::cout << "FragTrap " << this->_name << " Is Dead (0 hit points)!" << std::endl));
    if (this->_energyPoints < 1)
        return ((void)(std::cout << "FragTrap " << this->_name << " Not enough energy points to high five!" << std::endl));
    std::cout << "FragTrap " << this->_name << " request a high five!" << std::endl;
}
