/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:46:33 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/17 17:54:21 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
    public :
    //madatory subject functions
	//working
    //not working
    //others
    //working
    //not working
        Ice();
        Ice(Ice const & src);
        ~Ice();
        Ice & operator=(Ice const & rhs);
        AMateria *clone() const;
        void use(ICharacter &target);
};

#endif