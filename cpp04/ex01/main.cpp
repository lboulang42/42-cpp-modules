/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:01:01 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/19 17:07:47 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

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