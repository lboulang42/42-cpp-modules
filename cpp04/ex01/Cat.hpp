/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:35:07 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/13 20:20:46 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include <iostream>
#include "Brain.hpp"

class Cat : public Animal
{
  public:
	/*Constructeur par defaut*/
    Cat();
    /*Constructeur de recopie*/
    Cat(Cat const &src);
    /*Destructeur*/
    virtual ~Cat(void);
    /*Operator =*/
    Cat &operator=(Cat const &rhs);
  private:
    Brain *_brain;
};



#endif