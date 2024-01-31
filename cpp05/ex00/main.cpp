/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:01:01 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/31 18:29:38 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

int main (void)
{
	
	/* ********************************************************************** */
	std::cout << "===================================================" << std::endl;
	std::cout << "BUREAUCRAT CONSTRUCTOR EXCEPTION TESTS" << std::endl;
	std::cout << "===================================================" << std::endl;	

	std::cout << "===================================================" << std::endl;
	std::cout << "Should not throw exception " << std::endl;
	std::cout << "default constructor set _grade to 150" << std::endl;
	std::cout << "===================================================" << std::endl;
	try 
	{
		Bureaucrat test1;
		std::cout << test1 << std::endl;
	}
	catch (std::exception &error) 
	{
		std::cout << error.what() << "\n";
	}
	
	std::cout << "===================================================" << std::endl;
	std::cout << "Should not throw exception " << std::endl;
	std::cout << "_grade is set to 70, 1 and 150." << std::endl;
	std::cout << "===================================================" << std::endl;
	try 
	{
		Bureaucrat test1("test1", 70);
		std::cout << test1 << std::endl;	
		Bureaucrat test2("test2", 1);
		std::cout << test2 << std::endl;	
		Bureaucrat test3("test3", 150);
		std::cout << test3 << std::endl;	
	}
	catch (std::exception &error) 
	{
		std::cout << error.what() << "\n\n";
	}

	std::cout << "===================================================" << std::endl;
	std::cout << "Should throw exception GRADE TOO HIGH" << std::endl;
	std::cout << "_grade set to 0 (out of range [1,150])" << std::endl;
	std::cout << "===================================================" << std::endl;
	try 
	{
		Bureaucrat test1("test1", 0);
		std::cout << test1;	
	}
	catch (std::exception &error) 
	{
		std::cout << error.what() << "\n\n";
	}
	std::cout << "===================================================" << std::endl;
	std::cout << "Should throw exception GRADE TOO LOW" << std::endl;
	std::cout << "_grade set to 151 (out of range [1,150])" << std::endl;
	std::cout << "===================================================" << std::endl;
	try 
	{
		Bureaucrat test1("test1", 151);
		std::cout << test1;	
	}
	catch (std::exception &error) 
	{
		std::cout << error.what() << "\n\n";
	}
	/* ********************************************************************** */
	
	std::cout << "===================================================" << std::endl;
	std::cout << "BUREAUCRAT INCREMENT/DECREMENT EXCEPTION TESTS" << std::endl;
	std::cout << "===================================================" << std::endl;	

	std::cout << "===================================================" << std::endl;
	std::cout << "Should not throw exception " << std::endl;
	std::cout << "For increment _grade is set to 70, 2, 150. (69, 1, 149)" << std::endl;
	std::cout << "For decrement _grade is set to 70, 1, 149. (71, 2, 150)" << std::endl;
	std::cout << "===================================================" << std::endl;
	try 
	{
		Bureaucrat test1("test1", 70);
		test1.incrementGrade();
		std::cout << test1 << std::endl;	
		Bureaucrat test2("test2", 2);
		test2.incrementGrade();
		std::cout << test2 << std::endl;	
		Bureaucrat test3("test3", 150);
		test3.incrementGrade();
		std::cout << test3 << std::endl;

		Bureaucrat test4("test4", 70);
		test1.decrementGrade();
		std::cout << test4 << std::endl;	
		Bureaucrat test5("test5", 1);
		test5.decrementGrade();
		std::cout << test5 << std::endl;	
		Bureaucrat test6("test6", 149);
		test6.decrementGrade();
		std::cout << test6 << std::endl;	
	}
	catch (std::exception &error) 
	{
		std::cout << error.what() << "\n\n";
	}
	
	std::cout << "===================================================" << std::endl;
	std::cout << "Should throw exception GRADE TOO HIGH" << std::endl;
	std::cout << "For increment _grade is set to 1 = 0 (out of range [1,150])" << std::endl;
	std::cout << "===================================================" << std::endl;
	try 
	{
		Bureaucrat test1("test1", 0);
		test1.incrementGrade();
		std::cout << test1 << std::endl;	
	}
	catch (std::exception &error) 
	{
		std::cout << error.what() << "\n\n";
	}
	
	std::cout << "===================================================" << std::endl;
	std::cout << "Should throw exception GRADE TOO LOW" << std::endl;
	std::cout << "For increment _grade is set to 150 = 151 (out of range [1,150])" << std::endl;
	std::cout << "===================================================" << std::endl;
	try 
	{
		Bureaucrat test1("test1", 150);
		test1.decrementGrade();
		std::cout << test1 << std::endl;	
	}
	catch (std::exception &error) {
		std::cout << error.what() << "\n\n";
	}
	
	/* ********************************************************************** */
	std::cout << "===================================================" << std::endl;
	std::cout << "BUREAUCRAT GETTERS TESTS" << std::endl;
	std::cout << "===================================================" << std::endl;	
	try 
	{
		Bureaucrat test1("nom du bureaucrate", 12);
		std::cout << "Name: " << test1.getName() << std::endl;
		std::cout << "Grade: " << test1.getGrade() << std::endl;
	}
	catch (std::exception &error) 
	{
		std::cout << error.what() << "\n\n";
	}
}
