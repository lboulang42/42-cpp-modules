/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:25:36 by lboulang          #+#    #+#             */
/*   Updated: 2024/02/23 18:28:02 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>

#include <string.h>
#include <stack>

class RPN
{
    public:
        RPN(int ac, char **av);
        ~RPN();
        void parse(void);
        void execute(void);
        class InvalidChar : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return ("\033[1;31mError : InvalidChar\033[0m");
                }
        };
        class ArgsNumber : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return ("\033[1;31mError : ArgsNumber\033[0m");
                }
        };
        class ArgsEmpty : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return ("\033[1;31mError : Empty arguments\033[0m");
                }
        };
        class InvalidEquation : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return ("\033[1;31mError : InvalidEquation\033[0m");
                }
        };
        
    private:
        RPN();
        std::string _args;
        std::stack<int> _numStack;
        std::stack<char> _operatorStack;
        std::stack<int> _calculStack;
};


#endif