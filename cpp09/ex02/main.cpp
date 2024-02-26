/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:04:55 by lboulang          #+#    #+#             */
/*   Updated: 2024/02/26 18:11:58 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main (int ac, char **av)
{
    try
    { 
        PmergeMe pmerge(ac, av);
        
        pmerge.log(true);
        pmerge.vectorFord();
        pmerge.dequeFord();
        pmerge.log(false);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}