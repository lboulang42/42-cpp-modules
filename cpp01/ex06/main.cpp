/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:06:17 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/10 14:40:04 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

/*
Il arrive que vous n’ayiez pas envie de prêter attention à chacun des commentaires de Harl.
Implémentez un système permettant de filtrer ce qu’il dit selon les niveaux que vous acceptez d’entendre.
Concevez un programme prenant en paramètre un des quatre niveaux de gravité. 
Il affichera le message de ce niveau et tous ceux des niveaux supérieurs.

```
$> ./HarlFilter "WARNING"
[ WARNING ]
I think I deserve to have some extra bacon for free.
I've been coming for years whereas you started working here since last month.
[ ERROR ]
This is unacceptable, I want to speak to the manager now.
$> ./HarlFilter "I am not sure how tired I am today..."
[ Probably complaining about insignificant problems ]
```

Bien qu’il y ait plusieurs moyens de gérer Harl, l’un des plus efficaces est de le SWITCH off.
Appelez votre exécutable HarlFilter.
Vous devez utiliser, et peut-être découvrir, l’instruction switch dans cet exercice.
*/

/*
valids filters : 
	./HarlFilter DEBUG
	./HarlFilter INFO
	./HarlFilter WARNING
	./HarlFilter ERROR

other :
./HarlFilter "I am not sure how tired I am today..."

*/

int	main(int ac, char **av)
{
	std::string valid_filter[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	Harl newharl;
	if (ac != 2)
		return (std::cout << "Usage: ./harl <level>" << std::endl, 1);
	newharl.set_filter(av[1]);
	newharl.fullcomplain();
}
