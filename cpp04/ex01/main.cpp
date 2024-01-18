/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:01:01 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/18 21:01:39 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

/*
Les constructeurs et les destructeurs de chaque classe doivent afficher des messages qui leur sont propres.
Implémentez une classe Brain (cerveau) contenant un tableau de 100 std::string appelé ideas (idées).

Ainsi, les classes Dog et Cat auront un attribut privé Brain*.
À la construction, les classes Dog et Cat créeront leur Brain avec new Brain();
À la destruction, les classes Dog et Cat devront delete leur Brain.

Dans votre fonction main, créez et remplissez un tableau d’objets Animal dont la
moitié est composée d’objets Dog et l’autre moitié d’objets Cat.
À la fin de l’exécution du programme,
	parcourez ce tableau afin de delete chaque Animal.
Vous devez delete directement les chiens et les chats en tant qu’Animal.
Les destructeurs correspondants doivent être appelés dans le bon ordre.

N’oubliez pas de vérifier que vous n’avez pas de fuites de mémoire.

La copie d’un objet Dog ou d’un objet Cat ne doit pas être superficielle. 
Par conséquent,
	vous devez vous assurer que vos copies sont bien des copies profondes.

valgrind ./Animals
*/
#include <sstream>

int	main(void)
{
	
	Dog basic;
	{
		Dog tmp = basic;
		
	}

	// /*Subject Main*/
	
	// std::cout << "SUBJECT MAIN" << std::endl;
	// {
	// 	const Animal *j = new Dog();
	// 	const Animal *i = new Cat();
	// 	delete j; //should not create a leak
	// 	delete i;
	// }
	// std::cout << "\n\n\n";

	// /*check constructor destructor*/
	// std::cout << "CHECK CONSTRUCTOR DESTRUCTOR" << std::endl;
	// {
	// 	Animal *animals_array[100];
	// 	for (int i = 0; i < 100; i++)
	// 	{
	// 		if (i % 2)
	// 			animals_array[i] = new Dog();
	// 		else
	// 			animals_array[i] = new Cat();
	// 	}
	// 	for (int i = 0; i < 100; i++)
	// 		delete animals_array[i];
	// }
	// std::cout << "\n\n\n";
	
	
	// /*check deep copy*/
	// std::cout << "CHECK DEEP COPY" << std::endl;
	// {
	// 	Dog *dog1 = new Dog();
	// 	for (int i = 0; i < 100; i++)
	// 	{
	// 		std::stringstream ss;
	// 		ss << i;
	// 		dog1->setIdeas(i, "dog1 idea " + ss.str()); 
	// 	}
	// 	std::cout << "dog1 ideas :" << std::endl;
	// 	dog1->showIdeas();
	// 	std::cout << std::endl<< std::endl;

	// 	Dog *dog2 = new Dog(*dog1);
	// 	delete dog1;
	// 	std::cout << "dog2 ideas :" << std::endl;
	// 	dog2->showIdeas();
	// 	delete dog2;
	// }
	// std::cout << "\n\n\n";
}