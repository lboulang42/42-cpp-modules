/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:53:03 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/16 14:24:53 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
    public :
     
        Animal();
        Animal(Animal &src);
        ~Animal();
        Animal &operator=(Animal const &src);
    
        std::string getType(void) const;
        virtual void makeSound(void) const;//virtual fait en sorte que la fonction soit redefinie dans les classes derivees 

    protected :
        std::string _type;
};

#endif
