/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:05:10 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/16 19:33:42 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
    protected:
        std::string _type;
    public :
        /*Constructor*/
        AMateria(std::string const &type);
        /*destructor*/
        virtual ~AMateria();
        /*Copy*/
        AMateria(AMateria const &src);
        /*operator= */
        AMateria &operator=(AMateria const &src);
	    
        
        std::string const &getType() const; //Returns the materia type
	    virtual AMateria *clone() const = 0;
	    virtual void use(ICharacter &target);
};

#endif