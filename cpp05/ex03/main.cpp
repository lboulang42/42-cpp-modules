/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:03:51 by lboulang          #+#    #+#             */
/*   Updated: 2024/02/14 01:57:20 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main ( void )
{
	try
	{
		std::cout << "Test if Intern make a Form doesn't exist :" << std::endl;
		std::cout << "----------------------------------------" << std::endl;
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("FAKE_FORM", "Bender");
		Bureaucrat bender("Bender", 1);
		bender.signForm(*rrf);
		bender.executeForm(*rrf);

		delete rrf;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "----------------------------------------" << std::endl << std::endl << std::endl;
	}

	try
	{
		std::cout << "Test if Intern make a correct Form :" << std::endl;
		std::cout << "----------------------------------------" << std::endl;
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("PresidentialPardonForm", "Bender");
		Bureaucrat bender("Bender", 1);
		bender.signForm(*rrf);
		bender.executeForm(*rrf);
		std::cout << "----------------------------------------" << std::endl;

		delete rrf;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}