/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 19:51:55 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/13 20:09:20 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"


Brain::Brain()
{
    std::cout << "Brain Constructor called" << std::endl;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(Brain const &src)
{
    *this = src;
    std::cout << "Brain copy constructor called" << std::endl;
    
}

Brain &Brain::operator=(Brain const &rhs)
{
    std::cout << "Brain operator= called" << std::endl;
    (void)rhs;
    return (*this);
}
