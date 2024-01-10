/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 18:37:06 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/10 16:30:33 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
Create a zombie, give it a name and return it so it can be used outside of the
scope of the function. (+/- like alloc)
*/
Zombie* newZombie(std::string name)
{
	Zombie *zomb = new Zombie;	
	zomb->setname(name);
	return (zomb);
}
