/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:10:41 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/09 19:57:28 by lboulang         ###   ########.fr       */
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
    this->filter = 0;
    std::cout << "Harl Created" << std::endl;
}

Harl::Harl(char *filter_name)
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
    std::cout << "Harl Created" << std::endl;
    this->set_filter(filter_name);
}

Harl::~Harl()
{
    std::cout << "Harl destroyed" << std::endl;
}

void Harl::debug(void)
{
    std::cout << "[DEBUG]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !" << std::endl;
}

void Harl::info(void)
{
    std::cout << "[INFO]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;
}   

void Harl::warning(void)
{
    std::cout << "[WARNING]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
    std::cout << "[ERROR]" << std::endl;
    std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
}

void Harl::set_filter(std::string filter_name)
{
    std::cout << "called set_filted" << std::endl;
    std::cout << "filter_name = " << filter_name << std::endl;
    for (int i = 0; i < 4; i++)
    {
        std::cout << "this->level_tab[i] = " << this->level_tab[i].c_str() << std::endl;
        if (filter_name == this->level_tab[i].c_str())
        {
            std::cout << "touched" << std::endl;
            this->filter = i+1;
        }
    }
}

void Harl::nothing(void)
{
    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

void Harl::complain(std::string level)
{
    if (this->filter == -1)
        return ((void)(std::cout << "[ Probably complaining about insignificant problems ]" << std::endl));
    std::cout << "level = " << level << std::endl;
    std::cout << this->filter << std::endl;
    for (int i = 0; i < this->filter; i++)
        if (level == this->level_tab[i])
            return ((this->*complain_ptr[i])());
    return ;
}
