/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:49:58 by lboulang          #+#    #+#             */
/*   Updated: 2024/02/13 21:09:15 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
// #include "Bureaucrat.hpp"


ShrubberyCreationForm::ShrubberyCreationForm ( void ) : AForm("ShrubberyCreationForm", 145, 137), _target("default_shrubbery_target")
{
    std::cout << "ShrubberyCreationForm Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm ( std::string const &target ) : AForm("ShrubberyCreationForm", 145, 137), _target(target + "_shrubbery")
{
    std::cout << "ShrubberyCreationForm constructor with target called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm ( ShrubberyCreationForm const & src ) : AForm("ShrubberyCreationForm", 145, 137), _target(src._target)
{
    std::cout << "ShrubberyCreationForm Copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm ( void )
{
    std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	if (this != &rhs)
		this->_target = rhs._target;
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
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
