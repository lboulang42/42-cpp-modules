/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:52:42 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/12 20:13:25 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "ScavTrap constructor called" << std::endl;
    this->_hitpoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    this->_name = "edited";
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::guardGet(void)
{
    std::cout << "ScavTrap " << this->_name << " has entered in Gate keeper mode" << std::endl; 
}