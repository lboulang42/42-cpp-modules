/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:50:38 by lboulang          #+#    #+#             */
/*   Updated: 2024/02/16 11:50:39 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"


/*==========CANONICAL==========*/

/*default constructor*/
AForm::AForm() : _name("Default"), _signed(false), _grade_to_sign(1), _grade_to_execute(1)
{
	std::cout << "[AForm] - ";
	std::cout << "Default constructor called" << std::endl;
}


/*copy constructor*/
AForm::AForm(AForm &src) : _name(src.getName()), _signed(src.getSigned()), _grade_to_sign(src.getGradeToSign()), _grade_to_execute(src.getGradeToExecute())
{
	std::cout << "[AForm] - ";
	std::cout << "Copy constructor called" << std::endl;
	if (_grade_to_sign < 1 || _grade_to_execute < 1)
		throw AForm::GradeTooHighException();
	else if (_grade_to_sign > 150 || _grade_to_execute > 150)
		throw AForm::GradeTooLowException();
}

/*operator = */
AForm &AForm::operator=(AForm const &src)
{
	std::cout << "[AForm] - ";
	std::cout << "Assignation operator called" << std::endl;
	if (this != &src)
		*this = src;
	this->_signed = src.getSigned();
	return (*this);
}

/*destructor*/
AForm::~AForm()
{
	std::cout << "[AForm] - ";
	std::cout << "Destructor called" << std::endl;
}

/*==========OTHER CONSTRUCTOR==========*/
AForm::AForm(std::string name, int grade_to_sign, int grade_to_execute) : _name(name), _signed(false), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute)
{
	std::cout << "[AForm] - ";
	std::cout << "Constructor with name and grade called" << std::endl;
	if (grade_to_sign < 1 || grade_to_execute < 1)
		throw AForm::GradeTooHighException();
	else if (grade_to_sign > 150 || grade_to_execute > 150)
		throw AForm::GradeTooLowException();
}

/*==========GETTERS==========*/
std::string AForm::getName() const
{
	return (this->_name);
}

bool AForm::getSigned() const
{
	return (this->_signed);
}

int AForm::getGradeToSign() const
{
	if (this->_grade_to_sign < 1)
		throw AForm::GradeTooHighException();
	else if (this->_grade_to_sign > 150)
		throw AForm::GradeTooLowException();	
	return (this->_grade_to_sign);
}

int AForm::getGradeToExecute() const
{
	if (this->_grade_to_execute < 1)
		throw AForm::GradeTooHighException();
	else if (this->_grade_to_execute > 150)
		throw AForm::GradeTooLowException();
	return (this->_grade_to_execute);
}

/*==========MEMBER FUNCTIONS==========*/
void AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() <= this->_grade_to_sign)
		this->_signed = true;
	else
		throw AForm::GradeTooLowException();
}

/*==========EXCEPTIONS==========*/
const char *AForm::GradeTooHighException::what() const throw()
{
	return ("\e[0;35m[AForm::GradeTooHighException] - GRADE TOO HIGH\033[0m");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("\e[0;35m[AForm::GradeTooLowException] - GRADE TOO LOW\033[0m");
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return ("\e[0;35m[AForm::FormNotSignedException] - FORM NEED TO BE SIGNED TO BE EXECUTED\033[0m");
}


/*==========OTHER OPERATORS==========*/
std::ostream &operator<<(std::ostream &out, AForm const &b)
{
	out << b.getName() << ", Aform grade to sign " << b.getGradeToSign() << ", Aform grade to execute " << b.getGradeToExecute();
	return (out);
}
