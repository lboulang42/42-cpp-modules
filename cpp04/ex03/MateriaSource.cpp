/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:18:30 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/17 19:06:20 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource:: MateriaSource()
{
    std::cout << "[MATERIASOURCE] - ";
    std::cout << "Default constructor called" << std::endl;
    this->_materia[0] = NULL;
    this->_materia[1] = NULL;
    this->_materia[2] = NULL;
    this->_materia[3] = NULL;
}
MateriaSource::~MateriaSource()
{
    std::cout << "[MATERIASOURCE] - ";
    std::cout << "Destructor called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (this->_materia[i] != NULL)
            delete this->_materia[i];
    }
}
MateriaSource::MateriaSource(MateriaSource const &src)
{
    (void)src;
    std::cout << "[MATERIASOURCE] - ";
    std::cout << "Copy constructor called" << std::endl;

}
MateriaSource &MateriaSource::operator=(MateriaSource const &src)
{
    (void)src;
    std::cout << "[MATERIASOURCE] - ";
    std::cout << "Assignation operator called" << std::endl;
    return (*this);
}
        
void MateriaSource::learnMateria(AMateria *src)
{
    std::cout << "[MATERIASOURCE] - ";
    std::cout << "learnMateria called" << std::endl;
    
    for (int i = 0; i < 4; i++)
    {
        if (this->_materia[i] == NULL)
        {
            this->_materia[i] = src;
            return ;
        }
    }
    std::cout << "full" << std::endl;
}

//temp
AMateria *MateriaSource::createMateria(std::string const &type)
{
    std::cout << "[MATERIASOURCE] - ";
    std::cout << "createMateria called" << std::endl;
    // Retourne une nouvelle Materia. Celle-ci est une copie de celle apprise précédemment par la MateriaSource et dont le type est le même que celui passé en paramètre. Retourne 0 si le type est inconnu
    for (int i = 0; i < 4; i++)
    {
        if (this->_materia[i] != NULL)
        {
            if (this->_materia[i]->getType() == type)
                return (this->_materia[i]->clone());
        }
    } 
    std::cout << "Materia " << type << "not learned" << std::endl;
    return (0);
}
