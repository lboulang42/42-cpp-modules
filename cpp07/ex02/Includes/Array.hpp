/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:44:05 by lboulang          #+#    #+#             */
/*   Updated: 2024/02/17 18:59:43 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>

class Array
{
    public:
        Array();//create empty array
        Array(unsigned int n);//create array of size n
        Array(unsigned int n);
        Array(Array const &src);
        ~Array();
        Array &operator=(Array const &rhs);
    private:
        T *_array;
        unsigned int _size;
};

#endif
