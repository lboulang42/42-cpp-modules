/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 18:17:36 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/10 16:27:04 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*

Pour commencer, implémentez une classe Zombie. 
Elle possède un attribut privé : name (nom) de type string.
Ajoutez-lui une fonction membre void announce( void );.
Pour un zombie nommé Foo, le message serait :
	Foo: BraiiiiiiinnnzzzZ...
Ensuite, implémentez les fonctions suivantes :
	• Zombie* newZombie( std::string name ); 
	Crée un zombie, lui donne un nom et le retourne afin qu’il puisse être utilisé en dehors de la portée de la fonction.
	• void randomChump( std::string name ); Crée un zombie, lui donne un nom et le fait se présenter.

Quel est donc le but de l’exercice ?
Vous devez déterminez dans quel cas il est plus judicieux d’allouer les zombies sur le tas, et dans quel autre sur la pile.
Les zombies doivent être détruits lorsque vous n’en avez plus besoin.
Le destructeur doit afficher un message de débug comportant le nom du zombie.

*/


int	main(void)
{
	std::string names[10] = {
		"Bob", "John", "Jack", "Jill", "Jenny",
		"Jules", "Julie", "Michael", "Thomas", "Alex"
	};
	
	std::cout << "Using randomChump" << std::endl;
	for (int i = 0; i < 10; i++)
		randomChump(names[i]);
	
	std::cout << "Using newZombie" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		Zombie *tmpzomb = newZombie(names[i]);
		tmpzomb->announce();
		delete tmpzomb;
	}
	return (0);
}