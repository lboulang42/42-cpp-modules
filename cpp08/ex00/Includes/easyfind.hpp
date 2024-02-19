/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:44:05 by lboulang          #+#    #+#             */
/*   Updated: 2024/02/19 19:43:14 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>

template <typename T>
int *easyfind(T &container, int n) {
	T found = find(container.begin(), container.end(), n);
	if (found == container.end())
		return NULL;
	return &found;
}

// class Array
// {
// 	public:
// 		/*==========CANONICAL==========*/
// 		/*default constructor*/
// 		Array() : _array(new T[0]), _size(0) {};
// 		/*copy constructor*/
// 		Array (Array const &src) : _array(new T[src._size]), _size(src._size) {
// 			for (unsigned int i = 0; i < src._size; i++)
// 				_array[i] = src._array[i];
// 		};
// 		/*operator = */
// 		Array &operator=(Array const &src) {
// 			if (this != &src) {
// 				delete [] _array;
// 				_array = new T[src._size];
// 				_size = src._size;
// 				for (unsigned int i = 0; i < src._size; i++)
// 					_array[i] = src._array[i];
// 			}
// 			return *this;
// 		};
// 		/*destructor*/
// 		~Array() { delete [] _array; };

// 		/*==========OTHER CONSTRUCTORS==========*/
// 		Array(unsigned int n) : _array(new T[n]), _size(n) {
// 			for (unsigned int i = 0; i < n; i++)
// 				_array[i] = T();
// 		};

// 		/*==========OTHER OPERATORS==========*/
// 		T &operator[](unsigned int i) const {
// 			if (i >= _size)
// 				throw Array::OutOfRange();
// 			return _array[i];
// 		};

// 		/*==========GETTERS==========*/
// 		unsigned int size() const { return _size; };
		
// 		/*==========EXCEPTIONS==========*/
// 		class OutOfRange : public std::exception {
// 			public:
// 				virtual const char* what() const throw()
// 				{
// 					return ("[Array] - Index Out Of Range");
// 				}
// 		};

// 	private :
// 		T *_array;
// 		unsigned int _size;
// };

#endif
