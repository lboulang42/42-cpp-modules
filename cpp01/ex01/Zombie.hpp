/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 18:18:19 by lboulang          #+#    #+#             */
/*   Updated: 2023/12/31 17:13:11 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

# include <iostream>

class Zombie
{
	private:
		std::string name;
	public:
		Zombie(); /*Constructeur par defaut*/
		~Zombie(); /*Destructeur*/
		Zombie(const Zombie& value); /*Constructeur de recopie*/
		Zombie& operator=(const Zombie& other); /*Operator d'affectation*/
		
		void announce( void );
		void setname(std::string name);
};

Zombie* newZombie(std::string name);
Zombie* zombieHorde( int N, std::string name );

#endif