/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 18:17:36 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/10 16:33:32 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
Créez un programme comportant :
• Une variable de type string initialisée à "HI THIS IS BRAIN".
• stringPTR : Un pointeur sur la string.
• stringREF : Une référence sur la string.
Votre programme doit afficher :
• L’adresse de la string en mémoire.
• L’adresse stockée dans stringPTR.
• L’adresse stockée dans stringREF.
Puis :
• La valeur de la string.
• La valeur pointée par stringPTR.
• La valeur pointée par stringREF.

C’est tout. Il n’y a pas de pièges. 
Le but de cet exercice est de vous faire démystifier les références qui ne sont pas un concept totalement nouveau. 
Bien qu’il y ait de légères différences, il s’agit seulement d’une autre syntaxe pour représenter quelque chose que vous faites déjà : manipuler des adresses.
*/
#include <iostream>

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;
	std::cout << "Address of str: " << &str << std::endl;
	std::cout << "Address in stringPTR: " << stringPTR << std::endl;
	std::cout << "Address in stringREF: " << &stringREF << std::endl;

	std::cout << "Value of str: " << str << std::endl;
	std::cout << "Value pointed by stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value pointed by stringREF: " << stringREF << std::endl;

}