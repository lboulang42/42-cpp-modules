/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 21:09:30 by lboulang          #+#    #+#             */
/*   Updated: 2024/02/16 11:44:20 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

/*==========CANONICAL==========*/
/*default constructor*/
RobotomyRequestForm::RobotomyRequestForm ( ) : AForm("RobotomyRequestForm", 72, 45), _target("default_robotomy") 
{
    std::cout << "[RobotomyRequestForm] - ";
    std::cout << "Default Constructor called" << std::endl;
}

/*copy constructor*/
RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & src ) : AForm("RobotomyRequestForm", 72, 45), _target(src._target)
{
    std::cout << "[RobotomyRequestForm] - ";
    std::cout << "Copy Constructor called" << std::endl;
}

/*operator = */
RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &src)
{
    std::cout << "[RobotomyRequestForm] - ";
    std::cout << "Assignation operator called" << std::endl;
    if (this != &src)
        this->_target = src._target;
    return (*this);
}

/*destructor*/
RobotomyRequestForm::~RobotomyRequestForm ( void )
{
    std::cout << "[RobotomyRequestForm] - ";
    std::cout << "Destructor called" << std::endl;
}

/*==========OTHER CONSTRUCTOR==========*/
RobotomyRequestForm::RobotomyRequestForm ( std::string const &target ) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    std::cout << "[RobotomyRequestForm] - ";
    std::cout << "Constructor with target called" << std::endl;
}

/*==========MEMBER FUNCTIONS==========*/
void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    std::cout << "[RobotomyRequestForm] - ";
    std::cout << "execute() called" << std::endl;
    
	if (this->getSigned() == false)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::cout << "DRILLING NOISES GOES BRRRRRRRRR" << std::endl;
	srand(time(0));
    if (rand() % 2)
        std::cout << this->_target << " has been robotomized" << std::endl;
    else
        std::cout << this->_target << " robotomy failed" << std::endl;
}

