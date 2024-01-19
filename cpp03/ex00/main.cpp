/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:06:16 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/19 16:28:17 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int	main(void)
{
	ClapTrap a("user A");
	ClapTrap b("user B");
	ClapTrap c(a);
	ClapTrap d("tom");
	d = b;
	for (int i = 0; i < 10; i++)
	{
		std::cout << "Round " << i << std::endl;
		a.attack("user B");
		a.beRepaired(i);
		b.takeDamage(i/2);
	}	
}