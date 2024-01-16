/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:53:03 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/16 14:24:53 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
    public :
     
        WrongAnimal();
        WrongAnimal(WrongAnimal &src);
        ~WrongAnimal();
        WrongAnimal &operator=(WrongAnimal const &src);
    
        std::string getType(void) const;
        void makeSound(void) const;

    protected :
        std::string _type;
};

#endif
