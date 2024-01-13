/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:52:49 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/13 15:52:05 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
  public:
    /*Constructeur par defaut*/
    ScavTrap(std::string name);
    ScavTrap(ScavTrap const &src);
    /*Destructeur*/
    ~ScavTrap(void);
    /*Operator =*/  
    ScavTrap &operator=(ScavTrap const &rhs);

    void attack(std::string const & target);

    void guardGet(void);
};

#endif