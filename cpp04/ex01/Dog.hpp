/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:35:07 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/13 20:20:40 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
# include <iostream>
#include "Brain.hpp"

class Dog : public Animal
{
  public:
	/*Constructeur par defaut*/
    Dog();
    /*Constructeur de recopie*/
    Dog(Dog const &src);
    /*Destructeur*/
    virtual ~Dog(void);
    /*Operator =*/
    Dog &operator=(Dog const &rhs);
  private:
    Brain *_brain;
};

#endif