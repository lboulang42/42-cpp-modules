/*Generated using lboulang42's cppmain.sh*/

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main ( void )
{
	/* ********************************************************************** */
	std::cout << "===================================================" << std::endl;
	std::cout << "FORM CONSTRUCTOR EXCEPTION TESTS" << std::endl;
	std::cout << "===================================================" << std::endl;	

	std::cout << "===================================================" << std::endl;
	std::cout << "Should not throw exception " << std::endl;
	std::cout << "valid constructor _grade_to_sign and _grade_to_execute" << std::endl;
	std::cout << "===================================================" << std::endl;
	try 
	{
		Form test1;
		std::cout << test1 << std::endl;
		Form test2("test2", 150, 1);
		std::cout << test2 << std::endl;
		Form test3("test3", 70, 12);
		std::cout << test3 << std::endl;
	}
	catch (std::exception &error) 
	{
		std::cout << error.what() << "\n";
	}
	
	std::cout << "===================================================" << std::endl;
	std::cout << "Should throw exception " << std::endl;
	std::cout << "_grade_to_sign or _grade_to_execute out of range [1,150]" << std::endl;
	std::cout << "===================================================" << std::endl;
	try 
	{
		Form test1("max sign",0,12);
		std::cout << test1 << std::endl;
	}
	catch (std::exception &error) 
	{
		std::cout << error.what() << "\n\n";
	}
	try 
	{
		Form test1("min sign",151,12);
		std::cout << test1 << std::endl;
	}
	catch (std::exception &error) 
	{
		std::cout << error.what() << "\n\n";
	}
	try 
	{
		Form test1("max exec",1,0);
		std::cout << test1 << std::endl;
	}
	catch (std::exception &error) 
	{
		std::cout << error.what() << "\n\n";
	}
	try 
	{
		Form test1("min exec",1,151);
		std::cout << test1 << std::endl;
	}
	catch (std::exception &error) 
	{
		std::cout << error.what() << "\n\n";
	}
	/* ********************************************************************** */
	std::cout << "===================================================" << std::endl;
	std::cout << "FORM GETTERS TESTS" << std::endl;
	std::cout << "===================================================" << std::endl;
	try
	{
		Form test1("nomduform", 12, 13);
		std::cout << "Form name : "<< test1.getName() << std::endl;
		std::cout << "Form signed : "<< test1.getSigned() << std::endl;
		std::cout << "Form grade to sign : "<< test1.getGradeToSign() << std::endl;
		std::cout << "Form grade to execute :"<< test1.getGradeToExecute() << std::endl;
		std::cout << test1 << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "===================================================" << std::endl;
	std::cout << "BESIGNED TESTS" << std::endl;
	std::cout << "===================================================" << std::endl;
	std::cout << "===================================================" << std::endl;
	std::cout << "Should throw exception " << std::endl;
	std::cout << "form _grade_to_sign > bureaucrat _grade " << std::endl;
	std::cout << "===================================================" << std::endl;
	try
	{
		Form f1;
		Bureaucrat toolow("toolow", 150);
		std::cout << "trying to sign form level " << f1.getGradeToSign() << " with bureaucrat level " << toolow.getGrade() << std::endl;
		std::cout << "Form Signed Status : " << f1.getSigned() << std::endl;
		f1.beSigned(toolow);
		std::cout << "Form Signed Status : " << f1.getSigned() << std::endl;

	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "===================================================" << std::endl;
	std::cout << "Should not throw exception " << std::endl;
	std::cout << "form _grade_to_sign <= bureaucrat _grade " << std::endl;
	std::cout << "===================================================" << std::endl;
	try
	{
		Form f1;
		Form f2("f2", 2, 1);
		Bureaucrat highenough("toohigh", 1);
		std::cout << "trying to sign form level " << f1.getGradeToSign() << " with bureaucrat level " << highenough.getGrade() << std::endl;
		std::cout << "Form Signed Status : " << f1.getSigned() << std::endl;
		f1.beSigned(highenough);
		std::cout << "Form Signed Status : " << f1.getSigned() << std::endl;

		std::cout << "trying to sign form level " << f2.getGradeToSign() << " with bureaucrat level " << highenough.getGrade() << std::endl;
		std::cout << "Form Signed Status : " << f2.getSigned() << std::endl;
		f2.beSigned(highenough);
		std::cout << "Form Signed Status : " << f2.getSigned() << std::endl;

	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "===================================================" << std::endl;
	std::cout << "SIGNFORM TESTS" << std::endl;
	std::cout << "===================================================" << std::endl;
	std::cout << "===================================================" << std::endl;
	std::cout << "Should not throw exception " << std::endl;
	std::cout << "form _grade_to_sign <= bureaucrat _grade " << std::endl;
	std::cout << "===================================================" << std::endl;
	try
	{
		Bureaucrat highenough("highenough", 1);
		Form f1("f1", 150, 1);
		Form f2("f2", 70, 1);
		Form f3("f3", 1, 1);
		highenough.signForm(f1);
		highenough.signForm(f2);
		highenough.signForm(f3);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "===================================================" << std::endl;
	std::cout << "Should not throw exception " << std::endl;
	std::cout << "form _grade_to_sign <= bureaucrat _grade " << std::endl;
	std::cout << "===================================================" << std::endl;
	try
	{
		Bureaucrat toolow("toolow", 150);
		Form f1("f1", 150, 1);
		Form f2("f2", 70, 1);
		Form f3("f3", 1, 1);
		toolow.signForm(f1);
		toolow.signForm(f2);
		toolow.signForm(f3);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}