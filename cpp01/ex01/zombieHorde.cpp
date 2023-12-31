/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 17:12:58 by lboulang          #+#    #+#             */
/*   Updated: 2023/12/31 17:47:51 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	if (N < 1)
	{
		std::cout << "No zombie horde created" << std::endl;
		return (NULL);
	}
	Zombie *tab = new Zombie[N];
	for (int i = 0; i < N; i++)
		tab[i].setname(name);
	return (tab);
}