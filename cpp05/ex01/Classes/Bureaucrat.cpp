/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:14:27 by lboulang          #+#    #+#             */
/*   Updated: 2024/02/16 11:29:38 by lboulang         ###   ########.fr       */
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

/*destructor*/
Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor called" << std::endl;
}

/*==========OTHER CONSTRUCTOR==========*/
Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
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

/*==========MEMBER FUNCTIONS==========*/
void Bureaucrat::incrementGrade()
{
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}
void Bureaucrat::decrementGrade()
{
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

void Bureaucrat::signForm(Form &form)
{
	try 
	{
		form.beSigned(*this);
		std::cout << "\e[0;32m" << *this << " signed " << form << "\033[0m" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "\e[0;31m" << *this << " couldn't sign " << form << " because his grade is to low" << "\033[0m" << std::endl;
	}
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
