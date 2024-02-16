/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:08:48 by lboulang          #+#    #+#             */
/*   Updated: 2024/02/16 18:26:53 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

#include <iostream>
#include <cmath>

class Base
{
    public:
        Base();
        virtual ~Base()=0;
};

Base * generate(void);
void identify(Base &p);
void identify(Base* p);

#endif