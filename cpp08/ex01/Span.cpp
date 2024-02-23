/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:18:54 by lboulang          #+#    #+#             */
/*   Updated: 2024/02/23 14:49:35 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/*==========CANONICAL==========*/
Span::Span(void)
{
	std::cout << "Span default constructor called" << std::endl;
	this->_size = 0;
	this->_filled = 0;
	this->_array = new int[0];
}

Span::Span(Span const &src) : _size(src._size), _filled(src._filled)
{
	std::cout << "Span copy constructor called" << std::endl;
	this->_array = new int[src._size];
	for (size_t i = 0; i < src._filled; i++)
		this->_array[i] = src._array[i];
}

Span &Span::operator=(Span const &rhs)
{
	std::cout << "Span assignation operator called" << std::endl;
	if (this != &rhs)
	{
		delete[] this->_array;
		this->_size = rhs._size;
		this->_filled = rhs._filled;
		this->_array = new int[rhs._size];
		for (size_t i = 0; i < rhs._filled; i++)
			this->_array[i] = rhs._array[i];
	}
	return (*this);
}

Span::~Span()
{
	std::cout << "Span destructor called" << std::endl;
	delete[] this->_array;
}

/*==========OTHER CONSTRUCTORS==========*/
Span::Span(unsigned int n) : _size(n), _filled(0)
{
	std::cout << "Span constructor with param called" << std::endl;
	this->_array = new int[n];
}

/*==========MEMBER FUNCTIONS==========*/
void Span::addNumber(int n)
{
	std::cout << "Span addNumber called" << std::endl;
	if (_size == 0)
		throw Span::SizeZero();
	if (_filled == _size)
		throw Span::Full();
	_array[_filled] = n;
	_filled++;
}

void Span::displaySpan(void)
{
	for (size_t i = 0; i < this->_filled; i++)
		std::cout <<  "Span [" << i << "] : " << this->_array[i] << std::endl;
	for (size_t i = this->_filled; i < this->_size; i++)
		std::cout <<  "Span [" << i << "] : empty" << std::endl;
}

int Span::longestSpan(void)
{
	if (_size < 2)
		throw Span::TooSmall();
	std::sort(this->_array, this->_array + this->_filled);
	return (this->_array[this->_filled - 1] - this->_array[0]);
};
int Span::shortestSpan(void)
{
	int shortest;
	if (this->_filled < 2)
		throw Span::TooSmall();
	std::sort(this->_array, this->_array + this->_filled);
	for (size_t i = 0; i < this->_filled - 1; i++)
	{
		if (i == 0)
			shortest = this->_array[i + 1] - this->_array[i];
		shortest = this->_array[i + 1] - this->_array[i] < shortest ? this->_array[i + 1] - this->_array[i] : shortest;
	}
	return (shortest);
};
/*==========EXCEPTIONS==========*/

const char *Span::RangeTooLarge::what() const throw()
{
	return ("[Span] - Not enough space in Span to add range of numbers.");
}

const char *Span::EmptyRange::what() const throw()
{
	return ("[Span] - Span Empty Range (begin == end)");
}

const char *Span::InvalidRange::what() const throw()
{
	return ("[Span] - Span Invalid Range (begin > end)");
}

const char *Span::SizeZero::what() const throw()
{
	return ("Error: Span size is 0, cannot add elements");
}

const char *Span::Full::what() const throw()
{
	return ("Error: Span is full, cannot add more elements");
}

const char *Span::TooSmall::what() const throw()
{
	return ("Error: You need at least 2 elements to calculate span");
}
