/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:44:05 by lboulang          #+#    #+#             */
/*   Updated: 2024/02/19 17:00:45 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>


/*
Develop a class template Array that contains elements of type T and that implements
the following behavior and functions:
Tip: Try to compile int * a = new int(); then display *a.

As usual, ensure everything works as expected and turn in a main.cpp file that con-
tains your tests.
*/



template <typename T>

class Array
{
	public:
		/*==========CANONICAL==========*/
		/*default constructor*/
		Array() : _array(new T[0]), _size(0) {};
		/*copy constructor*/
		Array (Array const &src) : _array(new T[src._size]), _size(src._size) {
			for (unsigned int i = 0; i < src._size; i++)
				_array[i] = src._array[i];
		};
		/*operator = */
		Array &operator=(Array const &src) {
			if (this != &src) {
				delete [] _array;
				_array = new T[src._size];
				_size = src._size;
				for (unsigned int i = 0; i < src._size; i++)
					_array[i] = src._array[i];
			}
			return *this;
		};
		/*destructor*/
		~Array() { delete [] _array; };

		/*==========OTHER CONSTRUCTORS==========*/
		Array(unsigned int n) : _array(new T[n]), _size(n) {
			for (unsigned int i = 0; i < n; i++)
				_array[i] = T();
		};

		/*==========OTHER OPERATORS==========*/
		T &operator[](unsigned int i) const {
			if (i >= _size)
				throw Array::OutOfRange();
			return _array[i];
		};

		/*==========GETTERS==========*/
		unsigned int size() const { return _size; };
		
		/*==========EXCEPTIONS==========*/
		class OutOfRange : public std::exception {
			public:
				virtual const char* what() const throw()
				{
					return ("[Array] - Index Out Of Range");
				}
		};

	private :
		T *_array;
		unsigned int _size;
};

template <typename T>
std::ostream &operator<<(std::ostream &o, const Array<T>  &src) {
	for (unsigned int i = 0; i < src.size(); i++)
		o << "Array[" << i << "] : " << src[i] << std::endl;
	return o;
}



#endif
