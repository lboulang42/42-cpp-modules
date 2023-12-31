/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 18:35:41 by lboulang          #+#    #+#             */
/*   Updated: 2023/12/31 13:41:37 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
Create a zombie, give it a name and announce
*/
void randomChump(std::string name)
{
	Zombie zomb;
	zomb.setname(name); 
	zomb.announce();
}