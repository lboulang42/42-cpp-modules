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

class Cure : public AMateria
{
    public :
    //madatory subject functions
	//working
    //not working
    //others
    //working
    //not working
        Cure();
        Cure(Cure const & src);
        ~Cure();
        Cure & operator=(Cure const & rhs);
        AMateria *clone() const;
        void use(ICharacter &target);
};

#endif