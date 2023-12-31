/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 18:17:36 by lboulang          #+#    #+#             */
/*   Updated: 2023/12/31 17:49:06 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#include <stdlib.h>
/*
test main, create a zombie horde of size av[1] and name av[2]
valgrind --leak-check=full ./MoreBrainz 1000 tom
valgrind --leak-check=full ./MoreBrainz 0 pasdezombie
valgrind --leak-check=full ./MoreBrainz -8 bahnon
*/
int main(int ac, char **av)
{
	if (ac < 3)
		return (std::cout << "Usage: ./zombieHorde <size> <name>" << std::endl, 1);
	Zombie *tab = zombieHorde(atoi(av[1]), av[2]);
	if (!tab)
		return (1);
	for (int i = 0; i < atoi(av[1]); i++)
		tab[i].announce();	
	delete [] tab;
	return (0);
}