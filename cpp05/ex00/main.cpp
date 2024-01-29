/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:01:01 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/29 17:48:01 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Bureaucrat.hpp"

int main(void)
{

	{
		std::cout << "====================" << std::endl;
		std::cout << "TEST CANONICALL CLASS" << std::endl;
		std::cout << "====================" << std::endl;

		std::cout << "[TEST] : Default constructor" << std::endl;
		Bureaucrat a;
		std::cout << "[TEST] : Copy constructor" << std::endl;
		Bureaucrat b(a);
		std::cout << "[TEST] : Assignation operator" << std::endl;
		b = a;
		std::cout << "[TEST] : Destructor" << std::endl;
	}
	{
	    std::cout << "[TEST] : ptr, new, delete, deep copy..." << std::endl;	
		Bureaucrat *d = new Bureaucrat();
		Bureaucrat *c = new Bureaucrat();
		*c = *d;
		delete c;
		delete d;
	}
	{
		std::cout << "====================" << std::endl;
		std::cout << "TEST GRADE TOO HIGH" << std::endl;
		std::cout << "====================" << std::endl;
		try
		{
			Bureaucrat a(0, "a");
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "====================" << std::endl;
		std::cout << "TEST GRADE TOO LOW" << std::endl;
		std::cout << "====================" << std::endl;
		try
		{
			Bureaucrat a(151, "a");
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "====================" << std::endl;
		std::cout << "TEST VALID GRADE" << std::endl;
		std::cout << "====================" << std::endl;
		try
		{
			Bureaucrat a(12, "a");
			std::cout << "[TEST] : operator <<" << std::endl;
			std::cout << a << std::endl;
			std::cout << "[TEST] : incr/decr" << std::endl;
			std::cout << a << std::endl;
			++a;
			std::cout << a << std::endl;
			--a;
			std::cout << a << std::endl;
			std::cout << "[TEST] : GET NAME" << std::endl;
			std::cout << a.getGrade() << std::endl;
			std::cout << "[TEST] : GET GRADE" << std::endl;
			std::cout << a.getName() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "====================" << std::endl;
		std::cout << "TEST EXCEPTIONS" << std::endl;
		std::cout << "====================" << std::endl;
		try 
		{
			Bureaucrat a(1, "a");
			++a;
			std::cout << a << std::endl;
			std::cout << a.getGrade() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try {
			Bureaucrat b(150, "b");
			--b;
			std::cout << b << std::endl;
			std::cout << b.getGrade() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}
