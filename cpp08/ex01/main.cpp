/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:03:59 by lboulang          #+#    #+#             */
/*   Updated: 2024/02/29 14:51:24 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Span.hpp"

int main()
{
    try
    {
        std::cout << "============================================" << std::endl;
        std::cout << "MAIN FROM SUBJECT" << std::endl;
        std::cout << "============================================" << std::endl;
        Span s = Span(5);
        s.addNumber(17);
        s.addNumber(6);
        s.addNumber(3);
        s.addNumber(9);
        s.addNumber(11);
        std::cout << "shortest span = " << s.shortestSpan() << std::endl;
        std::cout << "longest span = " << s.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    
    try
    {
        std::cout << "============================================" << std::endl;
        std::cout << "TEST ITERATOR ADD NUMBER" << std::endl;
        std::cout << "============================================" << std::endl;
        Span s = Span(8);
        IteratorAddNumber(0, 8, s);
        s.displaySpan();
        std::cout << "shortest span = " << s.shortestSpan() << std::endl;
        std::cout << "longest span = " << s.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}