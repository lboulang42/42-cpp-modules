/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:44:05 by lboulang          #+#    #+#             */
/*   Updated: 2024/02/17 18:48:20 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
mplement a function template iter that takes 3 parameters and returns nothing.
•The first parameter is the address of an array.
•The second one is the length of the array.
•The third one is a function that will be call on every element of the array.
*/

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *array, int length, void (*f)(T const &))
{
    for (int i = 0; i < length; i++)
    {
        f(array[i]);
    }
}
template <typename T>
void mysteriousfunction(T const &x)
{
    std::cout << "mysteriousfunction has been called with param : " << x << std::endl;
}

#endif
