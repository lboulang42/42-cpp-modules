/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:03:04 by lboulang          #+#    #+#             */
/*   Updated: 2023/11/22 14:33:49 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

// #include <iostream>
// #include <sstream>
// #include <string>



int main(void)
{
    PhoneBook repertoire;
    std::string cmd;
    while (cmd != "EXIT")
    {
        std::cout << "Please Input Command" << std::endl;
        std::getline(std::cin, cmd);
        if (std::cin.eof())
            return (1);
        if (cmd == "ADD")
            repertoire.add(); 
        if (cmd == "SEARCH")
            repertoire.search();
    }
    std::cout << "Exiting Phone Book !" << std::endl;
    return 0;
}