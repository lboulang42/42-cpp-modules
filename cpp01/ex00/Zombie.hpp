/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 18:18:19 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/10 16:30:06 by lboulang         ###   ########.fr       */
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
		void announce( void );
		void setname(std::string name);
};

Zombie* newZombie(std::string name);
void	randomChump(std::string name);

#endif