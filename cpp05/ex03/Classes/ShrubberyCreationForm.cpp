/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:49:58 by lboulang          #+#    #+#             */
/*   Updated: 2024/02/16 11:44:10 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/*==========CANONICAL==========*/
/*default constructor*/
ShrubberyCreationForm::ShrubberyCreationForm ( void ) : AForm("ShrubberyCreationForm", 145, 137), _target("default_shrubbery_target")
{
	std::cout << "[ShrubberyCreationForm] - ";
	std::cout << "Default Constructor called" << std::endl;
}

/*copy constructor*/
ShrubberyCreationForm::ShrubberyCreationForm ( ShrubberyCreationForm const & src ) : AForm("ShrubberyCreationForm", 145, 137), _target(src._target)
{
	std::cout << "[ShrubberyCreationForm] - ";
	std::cout << "Copy Constructor called" << std::endl;
}

/*operator = */
ShrubberyCreationForm &ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	std::cout << "[ShrubberyCreationForm] - ";
	std::cout << "Assignation operator called" << std::endl;
	if (this != &rhs)
		this->_target = rhs._target;
	return (*this);
}

/*destructor*/
ShrubberyCreationForm::~ShrubberyCreationForm ( void )
{
	std::cout << "[ShrubberyCreationForm] - ";
	std::cout << "Destructor called" << std::endl;
}

/*==========OTHER CONSTRUCTOR==========*/
ShrubberyCreationForm::ShrubberyCreationForm ( std::string const &target ) : AForm("ShrubberyCreationForm", 145, 137), _target(target + "_shrubbery")
{
	std::cout << "[ShrubberyCreationForm] - ";
	std::cout << "Constructor with target called" << std::endl;
}

/*==========MEMBER FUNCTIONS==========*/
void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::cout << "[ShrubberyCreationForm] - ";
	std::cout << "execute() called" << std::endl;

	if (this->getSigned() == false)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::ofstream file;
	file.open(this->_target.c_str());
	if (file.is_open())
	{
		file << "\n\n";
		for (int i = 0; i < 3; i++)
		{
			file << "                        # #### ####" << std::endl;
            file << "                    ### \\/#|### |/####" << std::endl;
            file << "                   ##\\/#/ \\||/##/_/##/_#" << std::endl;
            file << "                 ###  \\/###|/ \\/ # ###" << std::endl;
            file << "               ##_\\_#\\_\\## | #/###_/_####" << std::endl;
            file << "              ## #### # \\ #| /  #### ##/##" << std::endl;
            file << "               __#_--###`  |{,###---###-~" << std::endl;
            file << "                         \\ }{" << std::endl;
            file << "                          }}{" << std::endl;
            file << "                          }}{" << std::endl;
            file << "                     ejm  {{}" << std::endl;
            file << "                    , -=-~{ .-^- _" << std::endl;
            file << "                          `}" << std::endl;
            file << "                           {" << std::endl;
			file << "		                  # #### ####" << std::endl << std::endl << std::endl;
		}
	}
	else 
		std::cerr << "Error: could not open file" << std::endl;
	file.close();
}
