/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 18:17:36 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/10 16:28:36 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#include <stdlib.h>
/*

Il est maintenant temps de créer une horde de Zombies !
Implémentez la fonction suivante dans le fichier correspondant :
	Zombie* zombieHorde( int N, std::string name );
Cette fonction doit allouer N objets Zombie en une seule allocation.
Ensuite, elle doit initialiser les zombies en donnant à chacun le nom passé en paramètre. 
Elle retourne un pointeur sur le premier zombie.
Écrivez vos propres tests afin de vous assurer que votre fonction zombieHorde() se comporte comme demandé.
Essayez d’appeler announce() pour chacun des zombies.
N’oubliez pas de tous les delete et de vérifiez que vous n’avez pas de fuites de
mémoire.

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