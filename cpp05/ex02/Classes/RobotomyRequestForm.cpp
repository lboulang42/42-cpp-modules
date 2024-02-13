/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 21:09:30 by lboulang          #+#    #+#             */
/*   Updated: 2024/02/13 21:25:45 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"


RobotomyRequestForm::RobotomyRequestForm ( ) : AForm("RobotomyRequestForm", 72, 45), _target("default_robotomy") 
{
    std::cout << "RobotomyRequestForm Default constructor called" << std::endl;
}


RobotomyRequestForm::RobotomyRequestForm ( std::string const &target ) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    std::cout << "RobotomyRequestForm constructor with target called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & src ) : AForm("RobotomyRequestForm", 72, 45), _target(src._target)
{
    std::cout << "RobotomyRequestForm Copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm ( void )
{
    std::cout << "RobotomyRequestForm Destructor called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
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

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &src)
{
    if (this != &src)
        this->_target = src._target;
    return (*this);
}