/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:03:59 by lboulang          #+#    #+#             */
/*   Updated: 2024/02/23 14:48:27 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Span.hpp"

int main()
{
    try
    {
        Span s = Span(5);
        s.addNumber(17);
        s.addNumber(6);
        s.addNumber(3);
        s.addNumber(9);
        s.addNumber(11);
        std::cout << "shortest span = " << s.shortestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    
    try
    {
        std::cout << "============================================" << std::endl;
        std::cout << "MAIN FROM SUBJECT" << std::endl;
        std::cout << "============================================" << std::endl;
        Span sp = Span(5);
        IteratorAddNumber(0, 5, sp);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        std::cout << "alors" << std::endl;
        Span *a = new Span(15);
        IteratorAddNumber(0, 8, *a);
        std::cout << "shortest span = " << a->shortestSpan() << std::endl;
        std::cout << "longest span = " << a->longestSpan() << std::endl;
        Span *b = new Span(*a);
        delete a;
        b->displaySpan();
        Span c = *b;
        delete b;
        c.displaySpan();
        Span d;
        d.addNumber(1);
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';

    }
    
    return 0;
}