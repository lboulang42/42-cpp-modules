/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:30:06 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/17 18:10:37 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "Ice.hpp"
class Character : public ICharacter
{
    public :
    //madatory subject functions
	//working
    //not working
    //others
    //working
    //not working
        Character(std::string const & name);
        Character(Character const & src);
        ~Character();
        Character & operator=(Character const & rhs);
        // std::string const & getName() const;
        std::string const &getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);//utilisera la Materia de l’emplacement[idx],et passera la cible en paramètre à la fonction AMateria::use.
    private :
        AMateria *_inventory[4];    
        std::string _name;
};

#endif

/*virtual void use(int idx, ICharacter& target) = 0;*/
/*virtual void use(ICharacter& target);*/