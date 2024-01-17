/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:33:27 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/17 19:09:23 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"


Character::Character(std::string const & name)
{
    std::cout << "[Character] - ";
    std::cout << "Constructor called" << std::endl;

    this->_name = name;
    this->_inventory[0] = NULL;
    this->_inventory[1] = NULL;
    this->_inventory[2] = NULL;
    this->_inventory[3] = NULL;
}
Character::Character(Character const & src)
{
    std::cout << "[Character] - ";
    std::cout << "Copy constructor called" << std::endl;

    (void)src;
}
Character::~Character()
{
    std::cout << "[Character] - ";
    std::cout << "Destructor called" << std::endl;
    /*delete inventory*/
    for (int i = 0 ; i < 4 ; i++)
    {
        if (this->_inventory[i] != NULL)
            delete this->_inventory[i];
    }
    /*delete throwed*/
}
Character & Character::operator=(Character const & rhs)
{
    std::cout << "[Character] - ";
    std::cout << "Assignation operator called" << std::endl;
    (void)rhs;
    return (*this);
}


// std::string const & getName() const
// {
//     return (this->_name);
// }


void Character::equip(AMateria* m)
{
    std::cout << "[Character] - ";
    std::cout << "Equip called" << std::endl;
    if (m == NULL)
    {
        std::cout << "Nothing to equip" << std::endl;
        return ;
    }
    for (int i = 0  ; i < 4 ; i++)
    {
        if (this->_inventory[i] == NULL)
        {
            this->_inventory[i] = m;
            std::cout << "Equip done" << std::endl;
            return ;
        }
    }
    std::cout << "Inventory full" << std::endl;
}

std::string const &Character::getName() const
{
    std::cout << "[Character] - ";
    std::cout << "getName called" << std::endl;
    return (this->_name);
}

void Character::unequip(int idx)
{
    std::cout << "[Character] - ";
    std::cout << "Unequip called" << std::endl;
    if (this->_inventory[idx] != NULL)
    {
        this->_inventory[idx] = NULL;
        std::cout << "Unequip done" << std::endl;
    }
    else
        std::cout << "Nothing to unequip" << std::endl;
    (void)idx;
}



void Character::use(int idx, ICharacter& target)//utilisera la Materia de l’emplacement[idx],et passera la cible en paramètre à la fonction AMateria::use.
{
    std::cout << "[Character] - ";
    std::cout << "Use called" << std::endl;
    if (this->_inventory[idx] != NULL)
    {
        this->_inventory[idx]->use(target);
        std::cout << "Use done" << std::endl;
    }
    else
        std::cout << "Nothing to use" << std::endl;
}