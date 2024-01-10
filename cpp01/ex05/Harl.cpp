/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:10:41 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/09 12:41:31 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"


Harl::Harl()
{
    this->level_tab[0] = "DEBUG";
    this->level_tab[1] = "INFO";
    this->level_tab[2] = "WARNING";
    this->level_tab[3] = "ERROR";
    this->complain_ptr[0] = &Harl::debug;
    this->complain_ptr[1] = &Harl::info;
    this->complain_ptr[2] = &Harl::warning;
    this->complain_ptr[3] = &Harl::error;
    std::cout << "Harl Created" << std::endl;
}

Harl::~Harl()
{
    std::cout << "Harl destroyed" << std::endl;
}

void Harl::debug(void)
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !" << std::endl;
}

void Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;
}   

void Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
    std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
    for (int i = 0; i < 4; i++)
        if (level == this->level_tab[i])
            return ((this->*complain_ptr[i])());
    return ((void)(std::cout << "Invalid complain level : '" << level << "'" << std::endl));
}
