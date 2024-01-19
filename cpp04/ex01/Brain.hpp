/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:12:18 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/19 17:07:59 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
	public :
		Brain();
		Brain(Brain const &src);
		~Brain();
		Brain &operator=(Brain const &src);
		void setIdeas(int i, std::string idea);
		void showIdeas(void);
	private :
		std::string _ideas[100];
};

#endif