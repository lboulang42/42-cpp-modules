/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:53:03 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/16 14:02:49 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <iostream>

class WrongCat: public WrongAnimal
{
    public : 
        WrongCat();
        WrongCat(WrongCat &src);
        ~WrongCat();
        WrongCat &operator=(WrongCat const &src);
        void makeSound(void) const;
};

#endif
