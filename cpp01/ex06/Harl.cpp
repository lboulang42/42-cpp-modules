/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:10:41 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/10 14:43:32 by lboulang         ###   ########.fr       */
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
    this->filter = -1;
}

Harl::~Harl()
{
}

void Harl::debug(void)
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\nI really do !" << std::endl;
    std::cout << std::endl;
}

void Harl::info(void)
{
	std::cout << "[INFO]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
    std::cout << "You didnt put enough bacon in my burger !" << std::endl;
	std::cout << "If you did, I wouldn't be asking for more !" << std::endl;
    std::cout << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
    std::cout << "I ve been coming for years whereas you started working here since last month." << std::endl;
    std::cout << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
    std::cout << std::endl;
}

void Harl::set_filter(char *av1)
{
	for (int i=0; i < 4; i++)
		if (av1 == this->level_tab[i])
            this->filter = i;
}

void Harl::nothing(void)
{
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

void Harl::fullcomplain(void)
{
    switch (this->filter)
    {
        case -1 :
            nothing();
            break;
        case 0: 
            debug();
        case 1 :
            info();
        case 2 :
            warning();
        case 3 :
            error();
    }
    return ;
}
