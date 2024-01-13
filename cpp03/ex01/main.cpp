/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:06:16 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/13 15:56:25 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap a("user A");
	a.attack("user B");
	a.guardGet();
	a.takeDamage(1000);
	a.attack("user B");
}