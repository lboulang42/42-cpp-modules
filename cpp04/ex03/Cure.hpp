/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:46:33 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/17 17:54:21 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Cure_HPP
# define Cure_HPP


#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Announce.hpp"

#ifdef __CLASS_NAME__
# undef __CLASS_NAME__
# define __CLASS_NAME__ "Cure"
#endif

#ifndef __CLASS_NAME__
# define __CLASS_NAME__ "Cure"
#endif

class Cure : public AMateria
{
	public :
		Cure();
		Cure(Cure const & src);
		~Cure();
		Cure & operator=(Cure const & rhs);
		AMateria *clone() const;
		void use(ICharacter &target);
};

#endif