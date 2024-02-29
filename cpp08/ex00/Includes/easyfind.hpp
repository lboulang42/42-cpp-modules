/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:44:05 by lboulang          #+#    #+#             */
/*   Updated: 2024/02/29 14:52:19 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>

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
