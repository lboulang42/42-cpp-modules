/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:36:49 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/13 17:38:00 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
  public:
	/*Constructeur par defaut*/
    WrongAnimal();
    /*Constructeur de recopie*/
    WrongAnimal(WrongAnimal const &src);
    /*Destructeur*/
    ~WrongAnimal(void);
    /*Operator =*/
    WrongAnimal &operator=(WrongAnimal const &rhs);

    void makeSound(void) const;  
    std::string getType(void) const;

  protected :
    std::string _type;
};



#endif