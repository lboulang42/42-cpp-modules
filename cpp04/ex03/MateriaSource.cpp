/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:18:30 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/18 20:34:43 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource:: MateriaSource()
{
 announce(__FUNCTION__, __CLASS_NAME__);
    this->_materia[0] = NULL;
    this->_materia[1] = NULL;
    this->_materia[2] = NULL;
    this->_materia[3] = NULL;
}
MateriaSource::~MateriaSource()
{
    announce(__FUNCTION__, __CLASS_NAME__);
    for (int i = 0; i < 4; i++)
    {
        if (this->_materia[i] && this->_materia[i] != NULL)
        {
            delete this->_materia[i];
            this->_materia[i] = NULL;
        }
    }
}
MateriaSource::MateriaSource(MateriaSource const &src)
{
    announce(__FUNCTION__, __CLASS_NAME__);
    for (int i=0; i < 4; i++)
    {
        if (src._materia[i] != NULL)
            this->_materia[i] = src._materia[i]->clone();
        else
            this->_materia[i] = NULL;
    }
}

MateriaSource &MateriaSource::operator=(MateriaSource const &src)
{
    announce(__FUNCTION__, __CLASS_NAME__);
    if (this != &src)
    {
        for (int i = 0; i < 4; i++)
        {
            if (this->_materia[i] != NULL)
            {
                delete this->_materia[i];
                this->_materia[i] = NULL;
            }
        }
    }
    return (*this);
}

/*Add */
void MateriaSource::learnMateria(AMateria *src)
{
    announce(__FUNCTION__, __CLASS_NAME__);
    for (int i = 0; i < 4; i++)
    {
        /*Avoid learning the same materia 2 times*/
        if (this->_materia[i] == src)
            return ((void)(std::cout << "Materia '" << src->getType() << "' already learned" << std::endl));
        if (this->_materia[i] == NULL)
        {
            std::cout << "Materia '" << src->getType() << "' learned" << std::endl;
            this->_materia[i] = src;
            return ;
        }
    }
    std::cout << "Can't learn more than 4 Materias, this materia" << src->getType() << " will be deleted" << std::endl;
    delete src;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    announce(__FUNCTION__, __CLASS_NAME__);
    for (int i = 0; i < 4; i++)
    {
        if (this->_materia[i] != NULL)
        {
            if (this->_materia[i]->getType() == type)
            {
                std::cout << "Materia '" << type << "' created" << std::endl;
                return (this->_materia[i]->clone());
            }
        }
    } 
    std::cout << "Materia '" << type << "' have not been created" << std::endl;
    return (0);
}
