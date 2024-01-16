/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:01:01 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/16 19:01:59 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

/*
Créer des objets Animal ne sert pas à grand-chose au final. Ils ne font aucun bruit !
Afin d’éviter les erreurs potentielles, la classe Animal de base ne doit pas être instanciable. 
Modifiez-la afin que personne ne puisse l’instancier. Votre code doit fonctionner comme avant.

valgrind ./Animals
*/
#include <sstream>

int	main(void)
{
	/*decommenter pour check la classe abstraite*/	
	// {
	// 	/*compile pas parceque Animal est devenu une classe Abstraite*/
	// 	Animal ani;
	// 	ani.makeSound();
	// }
	/*Subject Main*/
	{
		const Animal *j = new Dog();
		const Animal *i = new Cat();
		delete j; //should not create a leak
		delete i;
	}


	/*check constructor destructor*/
	{
		Animal *animals_array[100];
		for (int i = 0; i < 100; i++)
		{
			if (i % 2)
				animals_array[i] = new Dog();
			else
				animals_array[i] = new Cat();
		}
		for (int i = 0; i < 100; i++)
			delete animals_array[i];
	}
	
	
	/*check deep copy*/
	{
		Dog *dog1 = new Dog();
		for (int i = 0; i < 100; i++)
		{
			std::stringstream ss;
			ss << i;
			dog1->setIdeas(i, "dog1 idea " + ss.str()); 
		}
		std::cout << "dog1 ideas :" << std::endl;
		dog1->showIdeas();
		std::cout << std::endl<< std::endl;

		Dog *dog2 = new Dog(*dog1);
		delete dog1;
		std::cout << "dog2 ideas :" << std::endl;
		dog2->showIdeas();
		delete dog2;
	}
}