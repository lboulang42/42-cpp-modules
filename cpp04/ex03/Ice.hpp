/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:46:33 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/18 20:26:13 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include "Announce.hpp"
# include "ICharacter.hpp"

#ifdef __CLASS_NAME__
# undef __CLASS_NAME__
# define __CLASS_NAME__ "Ice"
#endif

#ifndef __CLASS_NAME__
# define __CLASS_NAME__ "Ice"
#endif


class Ice : public AMateria
{
  public:
	Ice();
	Ice(Ice const &src);
	~Ice();
	Ice &operator=(Ice const &rhs);
	AMateria *clone() const;
	void use(ICharacter &target);
};

#endif