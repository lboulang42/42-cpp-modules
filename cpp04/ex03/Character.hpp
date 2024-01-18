/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:30:06 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/18 20:26:43 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "Ice.hpp"
#include "Announce.hpp"


#ifdef __CLASS_NAME__
# undef __CLASS_NAME__
# define __CLASS_NAME__ "Character"
#endif

#ifndef __CLASS_NAME__
# define __CLASS_NAME__ "Character"
#endif

class Character : public ICharacter
{
	public :
		Character(std::string const & name);
		Character(Character const & src);
		~Character();
		Character & operator=(Character const & rhs);
		std::string const &getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
	private :
		AMateria *_inventory[4];    
		AMateria **_throwed;
		int _count_throwed;
		std::string _name;
};

#endif

/*virtual void use(int idx, ICharacter& target) = 0;*/
/*virtual void use(ICharacter& target);*/