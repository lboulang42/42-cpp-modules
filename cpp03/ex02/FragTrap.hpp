/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:52:49 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/13 16:11:57 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>

class FragTrap : public ClapTrap
{
  public:
	/*Constructeur par defaut*/
	FragTrap(std::string name);
	FragTrap(FragTrap const &src);
	/*Destructeur*/
	~FragTrap(void);
	/*Operator =*/
	FragTrap &operator=(FragTrap const &rhs);
	void highFivesGuys(void);
};

#endif