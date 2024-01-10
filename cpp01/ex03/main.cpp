/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 18:17:36 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/10 16:37:01 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

/*
Implémentez une classe Weapon (arme) qui possède :
	• Un attribut privé type de type string.
	• Une fonction membre getType() retournant une référence constante sur type.
	• Une fonction membre setType() qui attribue à type la nouvelle valeur passée en paramètre.

Maintenant, créez deux classes HumanA et HumanB.
Toutes deux possèdent une Weapon et un name, ainsi qu’une fonction membre attack() affichant (sans les chevrons bien sûr) :
	<name> attacks with their <weapon type>
HumanA et HumanB sont presque identiques, à l’exception de deux petits détails :
	• Alors que le constructeur de HumanA prend une Weapon comme paramètre, 
	ce n’est pas le cas de celui de HumanB.
	• HumanB n’aura pas toujours une Weapon, tandis que HumanA en aura forcément une.

Si votre implémentation est correcte, l’exécution du code suivant affichera une attaque avec "crude spiked club",
puis une attaque avec "some other type of club", pour les deux tests
*/


int	main(void)
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
}