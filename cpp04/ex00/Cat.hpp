/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:35:07 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/13 17:27:14 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include <iostream>

class Cat : public Animal
{
  public:
	/*Constructeur par defaut*/
    Cat();
    /*Constructeur de recopie*/
    Cat(Cat const &src);
    /*Destructeur*/
    ~Cat(void);
    /*Operator =*/
    Cat &operator=(Cat const &rhs);
};



#endif