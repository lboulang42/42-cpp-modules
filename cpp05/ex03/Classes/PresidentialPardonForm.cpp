/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 21:19:50 by lboulang          #+#    #+#             */
/*   Updated: 2024/02/16 11:44:26 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

/*==========CANONICAL==========*/
/*default constructor*/
PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("default_presidential")
{
	std::cout << "[PresidentialPardonForm] - ";
	std::cout << "Default Constructor called" << std::endl;
}

/*copy constructor*/
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : AForm("PresidentialPardonForm", 25, 5), _target(src._target)
{
	std::cout << "[PresidentialPardonForm] - ";
	std::cout << "Copy Constructor called" << std::endl;

}

/*operator = */
PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &src)
{
	std::cout << "[PresidentialPardonForm] - ";
	std::cout << "Assignation operator called" << std::endl;
    if (this != &src)
        this->_target = src._target;
    return (*this);
}

/*destructor*/
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "[PresidentialPardonForm] - ";
	std::cout << "Destructor called" << std::endl;
}

/*==========OTHER CONSTRUCTOR==========*/
PresidentialPardonForm::PresidentialPardonForm ( std::string const &target ) : AForm("PresidentialPardonForm", 145, 137), _target(target)
{
	std::cout << "[PresidentialPardonForm] - ";
	std::cout << "Constructor with target called" << std::endl;
}

/*==========MEMBER FUNCTIONS==========*/
void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	std::cout << "[PresidentialPardonForm] - ";
	std::cout << "execute() called" << std::endl;
	if (this->getSigned() == false)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::cout << this->_target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
