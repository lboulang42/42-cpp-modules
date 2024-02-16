/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 01:35:23 by lboulang          #+#    #+#             */
/*   Updated: 2024/02/16 11:49:17 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/*==========CANONICAL==========*/
/*default constructor*/
Intern::Intern ( void )
{
    std::cout << "[Intern] - ";
    std::cout << "Default Constructor called" << std::endl;
	_formName[0] = "ShrubberyCreationForm";
	_formName[1] = "RobotomyRequestForm";
	_formName[2] = "PresidentialPardonForm";
	_formType[0] = &Intern::makeShrubberyCreationForm;
	_formType[1] = &Intern::makeRobotomyRequestForm;
	_formType[2] = &Intern::makePresidentialPardonForm;
}

/*copy constructor*/
Intern::Intern(Intern const &src)
{
    *this = src;
    std::cout << "[Intern] - ";
    std::cout << "Copy Constructor called" << std::endl;
}

/*operator = */
Intern &Intern::operator=(Intern const &src)
{
    std::cout << "[Intern] - ";
    std::cout << "Assignation operator called" << std::endl;
    if (this != &src)
    {
        for (int i = 0; i < 3; i++)
        {
            this->_formName[i] = src._formName[i];
            this->_formType[i] = src._formType[i];
        }
    }
    return (*this);
}

/*destructor*/
Intern::~Intern()
{
    std::cout << "[Intern] - ";
    std::cout << "Destructor called" << std::endl;
}

/*==========MEMBER FUNCTIONS==========*/
AForm *Intern::makeForm(std::string const &form, std::string const &target)
{
    std::cout << "[Intern] - ";
    std::cout << "makeForm() called" << std::endl;
    for (int i = 0; i < 3; i++)
    {
        if (form == this->_formName[i])
        {
            std::cout << "Intern creates " << form << std::endl;
            return (this->*_formType[i])(target);
        }
    }
    std::cout << "Intern can't create " << form << " for target " << target << std::endl;
    throw Intern::WrongFormNameException();
}

AForm *Intern::makeShrubberyCreationForm(std::string const &target)
{
    std::cout << "[Intern] - ";
    std::cout << "makeShrubberyCreationForm() called" << std::endl;
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeRobotomyRequestForm(std::string const &target)
{
        std::cout << "[Intern] - ";
    std::cout << "makeRobotomyRequestForm() called" << std::endl;
	return (new RobotomyRequestForm(target));
}

AForm *Intern::makePresidentialPardonForm(std::string const &target)
{
    std::cout << "[Intern] - ";
    std::cout << "makePresidentialPardonForm() called" << std::endl;
	return (new PresidentialPardonForm(target));
}

/*==========EXCEPTIONS==========*/
const char *Intern::WrongFormNameException::what() const throw()
{
	return ("\e[0;35m[Intern::WrongFormNameException] - Wrong Form Name send to makeForm() \033[0m");
}
