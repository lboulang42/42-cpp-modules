/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:14:27 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/29 17:45:59 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*==========CANONICAL==========*/

/*default constructor*/
Bureaucrat::Bureaucrat(): _name("Default")
{
	std::cout << "Default constructor called" << std::endl;
	this->_grade = 150;
}

/*constructor with name and grade*/
/*Any attempt to instantiate a Bureaucrat using an invalid grade must throw an exception:
either a Bureaucrat::GradeTooHighException or a Bureaucrat::GradeTooLowException.*/
Bureaucrat::Bureaucrat(int grade, const std::string name): _name(name)
{
	std::cout << "Constructor with name and grade called" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

/*copy constructor*/
Bureaucrat::Bureaucrat(Bureaucrat &src): _name(src.getName()), _grade(src.getGrade())
{
	std::cout << "Copy Constructor called" << std::endl;
}

/*operator = */
Bureaucrat &Bureaucrat::operator=(Bureaucrat const &src)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_grade = src.getGrade();
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor called" << std::endl;
}

/*==========OPERATORS==========*/

Bureaucrat Bureaucrat::operator++(void)
{
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
	return (*this);
}

Bureaucrat Bureaucrat::operator--(void)
{
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
	return (*this);
}

/*==========GETTERS==========*/

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	return (this->_grade);
}

/*==========EXCEPTIONS==========*/
 
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("\e[0;35m[Bureaucrat::GradeTooHighException] - GRADE TOO HIGH\033[0m");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("\e[0;35m[Bureaucrat::GradeTooLowException] - GRADE TOO LOW\033[0m");
}

/*==========OTHER OPERATORS==========*/
std::ostream &operator<<(std::ostream &out, Bureaucrat const &b)
{
	
	out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return (out);
}
