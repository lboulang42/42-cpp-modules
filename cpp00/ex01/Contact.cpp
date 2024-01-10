/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:30:07 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/10 18:55:36 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

void Contact::ClearField()
{
	first_name = "";
	last_name = "";
	nickname = "";
	phone = "";
	secret = "";
}

std::string Contact::AddField(std::string name)
{
	std::string field; 
	std::cout << "Input your contact " << name << std::endl;
	std::getline(std::cin, field);
	if (std::cin.eof())
		exit(1);
	if (field.empty())
		return ((std::cout << "Your Contact can't have and empty field !\n"), "");
	int i;
	for (i=0; field[i]; i++)
		if (field[i] != ' ' && field[i] != '\t' && field[i] != '\n')
			break;
	field.erase(0, i);
	for (int i = 0; field[i]; i++)
	{
		if (!isspace(field[i]))
			return (field);
	}
	return ((std::cout << "Your Contact can't have and empty field !\n"), "");
}

int Contact::Add()
{
	first_name = AddField("first name");
	if (first_name == "")
		return (ClearField(), 0);
	last_name = AddField("last name");
	if (last_name == "")
		return (ClearField(), 0);
	nickname = AddField("nickname");
	if (nickname == "")
		return (ClearField(), 0);
	phone = AddField("phone number");
	if (phone == "")
		return (ClearField(), 0);
	secret = AddField("darkest secret");
	if (secret == "")
		return (ClearField(), 0);
    return (1);
}

void Contact::Show(int index)
{
	std::ostringstream tmp; // Use ostringstream instead of stringstream
	tmp << index;
	std::string str_index = tmp.str();	
	std::cout << "|" << Display(str_index) << "|";
	std::cout << Display(first_name) << "|";
	std::cout << Display(last_name) << "|";
	std::cout << Display(nickname) << "|" << std::endl;
}

void Contact::ShowLine()
{
    if (first_name.empty() && last_name.empty() && nickname.empty() && phone.empty() && secret.empty())
    {
        return ((void)(std::cout << "No Contact To Display" << std::endl));
    }
	std::cout << "FirstName : " << first_name << std::endl;
	std::cout << "Lastname : " << last_name << std::endl;
	std::cout << "Nickname : " << nickname << std::endl;
	std::cout << "PhoneNUmber : " << phone << std::endl;
	std::cout << "Secret : " << secret << std::endl;
}

std::string Contact::Display(std::string str)
{
	int len = str.length();
	std::string str2;
	if (str.length() > 10)
		return (str.substr(0, 9) += ".");
	for (int i = 0; i < 10 - len; i++)
		str2 += " ";
	str2 += str;
	return (str2);
}

Contact::~Contact()
{
}
