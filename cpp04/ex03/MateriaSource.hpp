/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:17:31 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/18 20:26:04 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include <string>
#include "Ice.hpp"
#include "Cure.hpp"
#include "Announce.hpp"

#ifdef __CLASS_NAME__
# undef __CLASS_NAME__
# define __CLASS_NAME__ "MateriaSource"
#endif

#ifndef __CLASS_NAME__
# define __CLASS_NAME__ "MateriaSource"
#endif

class MateriaSource : public IMateriaSource
{
    public:
        MateriaSource();
        ~MateriaSource();
        MateriaSource(MateriaSource const &src);
        MateriaSource &operator=(MateriaSource const &src);
        
        void learnMateria(AMateria *src);
        AMateria *createMateria(std::string const &type);
    private:
        AMateria *_materia[4];
};

#endif