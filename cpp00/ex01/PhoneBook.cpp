/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:11:00 by lboulang          #+#    #+#             */
/*   Updated: 2023/12/30 17:31:08 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	iterator = 0;
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::display_tab()
{
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|     index| firstname|  lastname|  nickname|" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::cout << "---------------------------------------------" << std::endl;
		ContactTab[i].Show(i); 
	}
	std::cout << "---------------------------------------------" << std::endl;
}

void PhoneBook::search()
{
	std::string input;
	int         number;
	
	display_tab();
	std::cout << "Which contact do you want to display ? (Input index)" << std::endl;
	std::getline(std::cin, input);
	if (std::cin.eof())
		exit(1);
	if (input.length() > 1 || !isdigit(input[0]))
		return ((void)(std::cout << "Error : Invalid Contact Index." << std::endl));
	number = atoi(&input[0]);
	if (number > 7)
		return ((void)(std::cout << "Error : Invalid Contact Index." << std::endl));
	ContactTab[number].ShowLine();
}

void PhoneBook::add()
{
	if (iterator == 8)
	{
		std::cout << "iterator set to 0" <<std::endl;
		iterator = 0;
	}
	if (ContactTab[iterator].Add())
		iterator++;
}
