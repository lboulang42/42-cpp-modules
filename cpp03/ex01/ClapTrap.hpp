/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:35:07 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/12 20:17:17 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
  public:
	/*Constructeur par defaut*/
    ClapTrap(std::string name);
    /*Constructeur de recopie*/
    ClapTrap(ClapTrap const &src);
    /*Destructeur*/
    ~ClapTrap(void);
    /*Operator =*/
    ClapTrap &operator=(ClapTrap const &rhs);

    void attack(std::string const & target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);


  protected:
    std::string _name;
    int _hitpoints;
    int _energyPoints;
    int _attackDamage;
};



#endif