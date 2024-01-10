/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:06:17 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/09 12:40:03 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

•Niveau "DEBUG" : Les messages de débug contiennent des informations contextuelles. 
    On les utilise principalement pour établir des diagnostics.
    Exemple : "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special ketchup burger. I really do !"
•Niveau "INFO" : Ces messages contiennent des informations détaillées. On les utilise pour tracer l’exécution d’un programme en production.
Exemple : "I cannot believe adding extra bacon costs more money. You didn’t put
enough bacon in my burger ! If you did, I wouldn’t be asking for more !"
•Niveau "WARNING" : Les messages d’avertissement indiquent un problème po-
tentiel dans le système. Toutefois, on est en mesure de le gérer ou de l’ignorer.
Exemple : "I think I deserve to have some extra bacon for free. I’ve been coming
for years whereas you started working here since last month."
•Niveau "ERROR" : Ces messages indiquent qu’une erreur irrécupérable s’est pro-
duite. Il s’agit généralement d’un problème critique qui nécessite une intervention
manuelle.
Exemple : "This is unacceptable ! I want to speak to the manager now."
11
C++ - Module 01
Allocation mémoire, pointeurs sur membres,
références, switch instruction
Vous allez automatiser Harl. Ce ne sera pas difficile étant donné qu’il se répète beau-
coup. Vous devez créer une classe Harl avec les fonctions membres privées suivantes :
•void debug( void );
•void info( void );
•void warning( void );
•void error( void );
Harl a également une fonction membre publique qui, selon le niveau passé en para-
mètre, fait appel à l’une des quatre fonctions membres ci-dessus :
void complain( std::string level );
Le but de l’exercice est de vous faire utiliser des pointeurs sur fonctions membres.
Ce n’est pas qu’une suggestion. Harl doit pouvoir se plaindre sans avoir recours à une
forêt de if/else if/else. Il n’y réfléchit pas à deux fois !
Créer et rendre des tests pour montrer que Harl se plaint beaucoup. Vous pouvez
utiliser les exemples de commentaires indiqué au dessus dans le sujet ou choisir d’utiliser
des commentaires de votre choix.
12

*/

#include "Harl.hpp"

int main(void)
{
    Harl harl;

    harl.complain("NOT A LEVEL");

    harl.complain("DEBUG");
    harl.complain("INFO");
    harl.complain("WARNING");
    harl.complain("ERROR");
    return (0);
}