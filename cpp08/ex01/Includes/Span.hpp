/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 20:54:25 by lboulang          #+#    #+#             */
/*   Updated: 2024/02/29 14:44:24 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>


class Span
{
	public:
		/*==========CANONICAL==========*/
		Span();
		Span(Span const &src);
		Span &operator=(Span const &rhs);
		~Span();
		
		/*==========OTHER CONSTRUCTORS==========*/
		Span(unsigned int n);
		
		/*==========MEMBER FUNCTIONS==========*/
		void addNumber(int n);
		void displaySpan(void);
		int longestSpan(void);
		int shortestSpan(void);
		
		/*==========EXCEPTIONS==========*/
		class TooSmall : public std::exception
		{
			public :
				virtual const char *what() const throw();
		};
		
		class Full : public std::exception
		{
			public :
				virtual const char *what() const throw();
		};
		
		class SizeZero : public std::exception
		{
			public :
				virtual const char *what() const throw();
		};
		
		class InvalidRange : public std::exception
		{
			public :
				virtual const char *what() const throw();
		};
		
		class EmptyRange : public std::exception
		{
			public :
				virtual const char *what() const throw();
		};
		
		class RangeTooLarge : public std::exception
		{
			public :
				virtual const char *what() const throw();
		};


	private:
		size_t _size;
		size_t _filled;
		int    *_array;
};

template <typename Iterator>
void IteratorAddNumber(Iterator begin, Iterator end, Span &span)
{
	if (begin > end)
		throw Span::InvalidRange();
	if (begin == end)
		throw Span::EmptyRange();
	for (Iterator it = begin; it != end; it++)
		span.addNumber(it);
}	

#endif  