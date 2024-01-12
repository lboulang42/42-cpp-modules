/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:01:02 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/12 17:43:26 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
/*
Concevez un programme prenant trois paramètres dans l’ordre suivant : 
	un nom de fichier et deux strings, s1 et s2.

Le fichier <filename> sera ouvert et son contenu copié dans un nouveau fichier <filename>.replace,
où chaque occurrence de s1 sera remplacée par s2.

Avoir recours aux fonctions C de manipulation de fichiers est interdit et sera considéré comme de la triche.
Toutes les fonctions membres de la classe std::string sont autorisées sauf replace. 
Utilisez-les intelligemment !
Bien entendu, vous devez gérer les entrées inattendues et les erreurs possibles.
Créez et rendez vos propres tests afin de prouver que votre programme fonctionne.

*/

int	main(int ac, char **av)
{
	if (ac != 4)
		return ((std::cout << "Wrong number of arguments : ./Sed filename s1 s2" << std::endl), 1);
	
	
	/*check infile && open infile*/
	std::string infile_name = av[1];
	std::ifstream infile;
	infile.open(infile_name.c_str());
	if (!infile.is_open())
		return ((std::cout << "File : '" << infile_name << "' does not exist or can't be opened" << std::endl), 1);
	
	/*create outfile && open outfile*/
	std::string outfile_name = infile_name + ".replace";
	std::ofstream outfile(outfile_name.c_str());
	if (!outfile.is_open())
	{
		infile.close();
		return ((std::cout << "File : '" << infile_name << "' can't be opened" << std::endl), 1);
	}

	/*get infile content*/	
	std::string infile_content;
	std::string s1 = av[2];
	std::string s2 = av[3];
	getline(infile, infile_content, '\0');
	if (s1 == "")
	{
		outfile << infile_content;
		infile.close();
		outfile.close();
		return (0);
	}
	while (infile_content.find(av[2]) != std::string::npos)
	{
		/*add infile_content in outfile till next s1 && append s2*/
		outfile <<  infile_content.substr(0, infile_content.find(s1)) << s2;
		/*update infile_content*/
		infile_content = infile_content.substr(infile_content.find(s1) + s1.length());
	}
	/*add last lines of infile to outfile*/
	outfile << infile_content;
	infile.close();
	outfile.close();
	return (0);
}
