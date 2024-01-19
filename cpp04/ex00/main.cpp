/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:01:01 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/19 17:05:09 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	/*Subject Main*/
	{
		const Animal *meta = new Animal();
		const Animal *j = new Dog();
		const Animal *i = new Cat();


		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
		delete meta;
		delete j;
		delete i;
	}
	
	/*test canonique*/
	// {
	//     std::cout << "==TESTING CANONIQUE==" << std::endl << std::endl;
	//     //animal
	//     Animal a;
	//     Animal b(a);
	//     Animal c;
	//     c = a;
	//     std::cout << "a : " << a.getType() << std::endl;
	//     std::cout << "b : " << b.getType() << std::endl;
	//     std::cout << "c : " << c.getType() << std::endl;
	//     //dog
	//     Dog d;
	//     Dog e(d);
	//     Dog f;
	//     f = d;
	//     std::cout << "d : " << d.getType() << std::endl;
	//     std::cout << "e : " << e.getType() << std::endl;
	//     std::cout << "f : " << f.getType() << std::endl;
	//     //cat
	//     Cat g;
	//     Cat h(g);
	//     Cat i;
	//     i = g;
	//     std::cout << "g : " << g.getType() << std::endl;
	//     std::cout << "h : " << h.getType() << std::endl;
	//     std::cout << "i : " << i.getType() << std::endl;

	//     std::cout << "====================" << std::endl;
	// }

	// /*Animal/Dog/Cat Test*/
	// {
	//     std::cout << "==TESTING Animal/Dog/Cat==" << std::endl << std::endl;
	//     std::cout << "== CONSTRUCTOR TESTS ==" << std::endl;
	//     std::cout << "creating an animal : new Animal" << std::endl;
	// 	const Animal *ani = new Animal();
	//     std::cout << std::endl;
	//     std::cout << "creating an animal : new Dog" << std::endl;
	// 	const Animal *dog = new Dog();
	//     std::cout << std::endl;
	//     std::cout << "creating an animal : new Cat" << std::endl;
	// 	const Animal *cat = new Cat();
	//     std::cout << "====================" << std::endl;
	//     std::cout << std::endl<< std::endl;

	//     std::cout << "== GETTYPE TESTS ==" << std::endl;  
	//     std::cout << "getType on dog :" << std::endl;
	// 	std::cout << dog->getType() << " " << std::endl<< std::endl;
	//     std::cout << "getType on cat :" << std::endl;
	// 	std::cout << cat->getType() << " " << std::endl << std::endl;
	//     std::cout << "getType on ani :" << std::endl;
	// 	std::cout << ani->getType() << " " << std::endl;
	//     std::cout << "====================" << std::endl;
	//     std::cout << std::endl<< std::endl; 
	//     std::cout << "== MAKESOUND TESTS ==" << std::endl;          
	//     std::cout << "makeSound on dog :" << std::endl;
	// 	dog->makeSound();
	//     std::cout << std::endl;
	//     std::cout << "makeSound on cat :" << std::endl;
	// 	cat->makeSound(); 
	//     std::cout << std::endl;
	//     std::cout << "makeSound on ani :" << std::endl;
	// 	ani->makeSound();
	//     std::cout << "====================" << std::endl; 
	//     std::cout << std::endl;
	//     std::cout << std::endl;
	//     delete ani;
	//     delete dog;
	//     delete cat;
	// }
	
	
	// /*WrongAnimal/WrongCat Test*/
	// {
	//     std::cout << "==TESTING WrongAnimal/WrongCat==" << std::endl << std::endl;
	//     std::cout << "== CONSTRUCTOR TESTS ==" << std::endl;
	//     std::cout << "creating an WrongAnimal : new WrongAnimal" << std::endl;
	// 	const WrongAnimal *wronganimal = new WrongAnimal();
	//     std::cout << std::endl;
	//     std::cout << "creating an WrongAnimal : new WrongCat" << std::endl;
	// 	const WrongAnimal *wrongcat = new WrongCat();
	//     std::cout << std::endl<< std::endl;

	//     std::cout << "== GETTYPE TESTS ==" << std::endl;  
	//     std::cout << "getType on Wrongcat :" << std::endl;
	// 	std::cout << wrongcat->getType() << " " << std::endl << std::endl;
		
	//     std::cout << "getType on Wronganimal :" << std::endl;
	// 	std::cout << wronganimal->getType() << " " << std::endl<< std::endl;
	//     std::cout << "====================" << std::endl;  
		
	//     std::cout << "== MAKESOUND TESTS ==" << std::endl;          
	//     std::cout << std::endl;
	//     std::cout << "makeSound on Wrongcat :" << std::endl;
	// 	wrongcat->makeSound(); 
	//     std::cout << std::endl;
	//     std::cout << "makeSound on Wronganimal :" << std::endl;
	// 	wronganimal->makeSound();
	//     std::cout << "====================" << std::endl;  
	//     delete wronganimal;
	//     delete wrongcat;
	// }
}