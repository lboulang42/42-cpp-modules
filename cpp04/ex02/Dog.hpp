/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:53:03 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/16 18:34:59 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include <iostream>
# include "Brain.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(Dog const &src);
		~Dog();
		Dog &operator=(Dog const &src);
        void makeSound(void) const;
		void setIdeas(int i, std::string idea);
		void showIdeas(void);
	private :
		Brain *_brain;
};

#endif
