/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:18:30 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/17 23:41:04 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

/*Default Constructor*/
MateriaSource::MateriaSource(void)
{
    std::cout << "[MATERIASOURCE] - ";
    std::cout << "Default constructor called" << std::endl;
    this->_materia[0] = NULL;
    this->_materia[1] = NULL;
    this->_materia[2] = NULL;
    this->_materia[3] = NULL;
}



/*Copy Constructor*/
MateriaSource::MateriaSource(MateriaSource const &src)
{
    std::cout << "[MATERIASOURCE] - ";
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

/*Destructor*/
MateriaSource::~MateriaSource()
{
    // std::cout << "[MATERIASOURCE] - ";
    // std::cout << "Destructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        if (this->_materia[i] != NULL)
            delete this->_materia[i];
}


MateriaSource	&MateriaSource::operator=(MateriaSource const &src) {
	
    if (this != &src)
    {
        for (int i = 0; i < 4; i++)
        {
			if (this->_materia[i])
				delete _materia[i];
			if (src.getMateria(i))
				this->_materia[i] = src.getMateria(i)->clone();
		}
    }
	return *this;
}

void MateriaSource::learnMateria(AMateria *src)
{
    // std::cout << "[MATERIASOURCE] - ";
    // std::cout << "learnMateria called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (this->_materia[i] == NULL)
        {
            this->_materia[i] = src;
            std::cout << "Materia " << src->getType() << " learned" << std::endl;
            return ;
        }
    }
    std::cout << "learnMateria array is full" << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    // std::cout << "[MATERIASOURCE] - ";
    // std::cout << "createMateria called" << std::endl;
    for (int i = 0; i < 4; i++)
        if (this->_materia[i] != NULL && this->_materia[i]->getType() == type)
            return (this->_materia[i]->clone());
    std::cout << "Materia " << type << "not learned" << std::endl;
    return (0);
}


AMateria *MateriaSource::getMateria(int i) const
{
    std::cout << "[MATERIASOURCE] - ";
    std::cout << "getMateria called" << std::endl;
    return (this->_materia[i]);
}