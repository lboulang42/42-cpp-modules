/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:44:05 by lboulang          #+#    #+#             */
/*   Updated: 2024/02/21 20:48:48 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
/*
Écrivez une fonction template easyfind acceptant un type T. Elle prend deux para-
mètres. Le premier est de type T et le second un nombre entier.
Partant du principe que T est un container d’entiers, cette fonction doit trouver la
première occurrence du second paramètre dans le premier paramètre.
Si aucune occurrence n’a été trouvée, vous pouvez soit jeter une exception, soit re-
tourner une valeur d’erreur de votre choix. Si vous avez besoin d’inspiration, jetez un oeil
au comportement des containers standards
*/

class NotFound : public std::exception {
	public:
		virtual const char* what() const throw()
		{
			return ("[easyfind()] - n not found in container.");
		}
};

template <typename T>
int *easyfind(T &container, int n)
{
	typename T::iterator it;
	it = find(container.begin(), container.end(), n);
	if (it != container.end())
		return &(*it);
	throw NotFound();
}






#endif
