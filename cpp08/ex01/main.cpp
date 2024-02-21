/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:03:59 by lboulang          #+#    #+#             */
/*   Updated: 2024/02/21 20:51:43 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "easyfind.hpp"
#include <vector>

int main()
{
   
    try
    {
        std::cout << "============================================" << std::endl;
        std::cout << "CHECKING FOR A VALUE IN THE VECTOR : " << std::endl;
        std::cout << "============================================" << std::endl;
        std::vector<int> v;
        for (int i = 0; i < 10; i++)
        {
            v.push_back(i * 4); // 0 4 8 12 16 20 24 28 32 36
        }
        std::cout << "vector[7] = " << v.at(7) << std::endl << std::endl;
        
        int *ptr = easyfind(v, 28);
        std::cout << "Value pointed by ptr returned by easyfind : " << *ptr << std::endl << std::endl;
        
        std::cout << "changing the value pointed by ptr to 12 should change the value in the vector" << std::endl;
        *ptr = 12;
        std::cout << "vector[7] after change = " << v.at(7) << std::endl;
        std::cout << "============================================" << std::endl;
        
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    
    try
    {
        std::cout << "============================================" << std::endl;
        std::cout << "CHECKING FOR A VALUE NOT IN THE VECTOR : " << std::endl;
        std::cout << "============================================" << std::endl;
        std::vector<int> v;
        for (int i = 0; i < 10; i++)
        {
            v.push_back(i); // 0 1 2 3 4 5 6 7 8 9
        }
        int *ptr = easyfind(v, 12);
        std::cout << "value pointed by ptr returned by easyfind : " << *ptr << std::endl;
        
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    
    return 0;
}