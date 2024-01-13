/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 19:52:04 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/13 19:53:43 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
# define BRAIN_H

#include <iostream>

class Brain
{
    public:
        Brain();
        ~Brain();
        Brain(Brain const &src);
        Brain &operator=(Brain const &rhs);
        

        





    private:
        std::string ideas[100];
};

#endif