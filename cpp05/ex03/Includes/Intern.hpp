/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 01:33:30 by lboulang          #+#    #+#             */
/*   Updated: 2024/02/16 11:48:31 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

class AForm;

class Intern
{
    public:
        /*==========CANONICAL==========*/
        /*default constructor*/
        Intern();
        /*copy constructor*/
        Intern(Intern const &src);
        /*operator = */
        Intern &operator=(Intern const &src);
        /*destructor*/
        ~Intern();
        
        /*==========MEMBER FUNCTIONS==========*/
        AForm *makeForm(std::string const &form, std::string const &target);
        AForm *makeShrubberyCreationForm(std::string const &target);
        AForm *makeRobotomyRequestForm(std::string const &target);
        AForm *makePresidentialPardonForm(std::string const &target);

        /*==========EXCEPTIONS==========*/        
        class WrongFormNameException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
    
    private : 
        std::string _formName[3];
        AForm *(Intern::*_formType[3])(std::string const &target);
};

#endif