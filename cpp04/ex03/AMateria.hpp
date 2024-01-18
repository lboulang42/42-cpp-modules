/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:39:45 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/18 20:26:37 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include "Announce.hpp"

#ifdef __CLASS_NAME__
# undef __CLASS_NAME__
# define __CLASS_NAME__ "AMateria"
#endif

#ifndef __CLASS_NAME__
# define __CLASS_NAME__ "AMateria"
#endif

class ICharacter;

class AMateria
{
	public:
		AMateria(std::string const &type);
		AMateria &operator=(AMateria const &src);
		virtual ~AMateria();

		std::string const &getType() const;
		virtual void use(ICharacter &target);		
		virtual AMateria *clone() const = 0;

	protected :
		std::string _type;
};


#endif
