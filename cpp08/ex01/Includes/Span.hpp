/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 20:54:25 by lboulang          #+#    #+#             */
/*   Updated: 2024/02/21 21:19:03 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>


class Span
{
    public:
        Span(unsigned int n);
        Span(Span const &src);
        ~Span();
        Span &operator=(Span const &rhs);
        void addNumber(int n);
        int shortestSpan()
        {
            if (_size < 2)
                throw std::exception();
            
        };
        int longestSpan()
        {
            if (_size < 2)
                throw std::exception();
        };
    private:
        Span();
        unsigned int _n;
        unsigned int _size;
        int *_array;
};

#endif  