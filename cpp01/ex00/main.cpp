/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 18:17:36 by lboulang          #+#    #+#             */
/*   Updated: 2023/12/31 13:39:11 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	std::string names[10] = {
		"Bob", "John", "Jack", "Jill", "Jenny", "Jules", 
		"Julie", "Michael", "Thomas", "Alex"
	};

	std::cout << "Using randomChump" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		randomChump(names[i]);
	}

	std::cout << "Using newZombie" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		Zombie *tmpzomb = newZombie(names[i]);
		tmpzomb->announce();
		delete tmpzomb;
	}
	return (0);
}