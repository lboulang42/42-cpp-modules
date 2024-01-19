/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:06:16 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/19 16:36:32 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	FragTrap frag("frag");

	frag.attack("user B");
	frag.highFivesGuys();
	frag.takeDamage(1000);
	frag.attack("user B");
	frag.takeDamage(10);
	frag.beRepaired(1000);
	frag.takeDamage(10000);
	frag.highFivesGuys();
}