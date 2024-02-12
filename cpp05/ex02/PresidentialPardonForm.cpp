/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:58:58 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/31 19:03:44 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/*==========CANONICAL==========*/

/*default constructor*/
PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25,5)
{
    this->_target = "Default";  
	std::cout << "[AForm] - ";
	std::cout << "Default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25,5)
{
    this->_target = target;  
	std::cout << "[AForm] - ";
	std::cout << "string constructor called" << std::endl;
}

/*copy constructor*/
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &src) : AForm(src.getName(), src.getGradeToSign(), src.getGradeToExecute())
{
    this->_target = src.getTarget();  
    std::cout << "[AForm] - ";
    std::cout << "Copy constructor called" << std::endl;
}

/*operator = */
PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &src)
{
	std::cout << "[AForm] - ";
	std::cout << "Assignation operator called" << std::endl;
	if (this != &src)
	{
		*this = src;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "[AForm] - ";
	std::cout << "Destructor called" << std::endl;
}