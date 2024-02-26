/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:26:58 by lboulang          #+#    #+#             */
/*   Updated: 2024/02/26 19:24:18 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


/*
parse date format
parse date valide (time)
parse value format
parse value (entre 0 et max int)

execute : 
    - create a map with date as key and value as value
    - print the map
*/

bool check_line(std::string& line)
{
    if (line.size() < 14)
        return false;
    if (line.find(" | ") == std::string::npos)
        return false;

    std::string date = line.substr(0, 10);
    std::string value = line.substr(13);

    if (date.size() != 10 || value.empty())
        return false;

    for (char c : date)
    {
        if (!isdigit(c) && c != '-')
            return false;
    }

    bool hasDecimalPoint = false;
    for (char c : value)
    {
        if (!isdigit(c) && c != '.')
            return false;
        if (c == '.')
        {
            if (hasDecimalPoint)
                return false;
            hasDecimalPoint = true;
        }
    }

    return true;
}

bool check_line(std::string &line)
{
    

//     if (line.size() < 14)
//         return false;
//     if (line.find(" | ") == std::string::npos)
//         return false;
//     if (!isdigit(line[0]) || !isdigit(line[1]) || !isdigit(line[2]) || !isdigit(line[3]) || !isdigit(line[5]) || !isdigit(line[6]) || !isdigit(line[8]) || !isdigit(line[9]))
//         return false;
//     return true;
}

BitcoinExchange::BitcoinExchange(int ac, char **av)
{
    if (ac != 2)
        throw nArgs();
    std::ifstream file(av[1]);
    if (!file.is_open())
        throw readFile();
    
    
    std::string line;
    getline(file, line);
    if (line != "date | value")
        throw Error();

    while (getline(file, line))
    {
        
        if (!check_line(line))
            std::cout << "bad input : " << line << std::endl;
        else
            std::cout << line << std::endl;
        /* code */
    }
    
    
    
    file.close();
    //line < 15 : bad input
    //if [0,3] && [5,6] && [8-9] not digit :  bad input

}