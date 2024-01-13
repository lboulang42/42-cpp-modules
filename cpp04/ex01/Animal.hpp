/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:35:07 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/13 17:28:28 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
  public:
	/*Constructeur par defaut*/
    Animal();
    /*Constructeur de recopie*/
    Animal(Animal const &src);
    /*Destructeur*/
    ~Animal(void);
    /*Operator =*/
    Animal &operator=(Animal const &rhs);

    void makeSound(void) const;  
    std::string getType(void) const;

  protected :
    std::string _type;
};



#endif