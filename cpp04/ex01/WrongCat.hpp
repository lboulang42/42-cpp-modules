/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:35:07 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/13 17:41:27 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <iostream>

class WrongCat : public WrongAnimal
{
  public:
	/*Constructeur par defaut*/
    WrongCat();
    /*Constructeur de recopie*/
    WrongCat(WrongCat const &src);
    /*Destructeur*/
    ~WrongCat(void);
    /*Operator =*/
    WrongCat &operator=(WrongCat const &rhs);
  private :
    std::string _type;
};



#endif