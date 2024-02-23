/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 20:54:25 by lboulang          #+#    #+#             */
/*   Updated: 2024/02/23 16:08:29 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <algorithm>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		/*==========CANONICAL==========*/
		MutantStack() : std::stack<T>(){
			std::cout << "MutantStack default constructor called" << std::endl;
		}
		MutantStack(MutantStack const &src) : std::stack<T>(src) {
			std::cout << "MutantStack copy constructor called" << std::endl;    
		}
		MutantStack &operator=(MutantStack const &rhs) {
			std::cout << "MutantStack assignation operator called" << std::endl;
			std::stack<T>::operator=(rhs);
			return (*this); 
		}
		~MutantStack() {
			std::cout << "MutantStack destructor called" << std::endl;
		}

		/*==========MEMBER FUNCTIONS==========*/
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin() {
			return (std::stack<T>::c.begin());
		}
		iterator end() {
			return (std::stack<T>::c.end());
		}
	private:
};

#endif