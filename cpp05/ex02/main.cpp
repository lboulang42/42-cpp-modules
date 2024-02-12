/*Generated using lboulang42's cppmain.sh*/

#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main ( void )
{

	
	// /* ********************************************************************** */
	// std::cout << "===================================================" << std::endl;
	// std::cout << "AForm CONSTRUCTOR EXCEPTION TESTS" << std::endl;
	// std::cout << "===================================================" << std::endl;	

	// std::cout << "===================================================" << std::endl;
	// std::cout << "Should not throw exception " << std::endl;
	// std::cout << "valid constructor _grade_to_sign and _grade_to_execute" << std::endl;
	// std::cout << "===================================================" << std::endl;
	// try 
	// {
	// 	AForm test1;
	// 	std::cout << test1 << std::endl;
	// 	AForm test2("test2", 150, 1);
	// 	std::cout << test2 << std::endl;
	// 	AForm test3("test3", 70, 12);
	// 	std::cout << test3 << std::endl;
	// }
	// catch (std::exception &error) 
	// {
	// 	std::cout << error.what() << "\n";
	// }
	
	// std::cout << "===================================================" << std::endl;
	// std::cout << "Should throw exception " << std::endl;
	// std::cout << "_grade_to_sign or _grade_to_execute out of range [1,150]" << std::endl;
	// std::cout << "===================================================" << std::endl;
	// try 
	// {
	// 	AForm test1("max sign",0,12);
	// 	std::cout << test1 << std::endl;
	// }
	// catch (std::exception &error) 
	// {
	// 	std::cout << error.what() << "\n\n";
	// }
	// try 
	// {
	// 	AForm test1("min sign",151,12);
	// 	std::cout << test1 << std::endl;
	// }
	// catch (std::exception &error) 
	// {
	// 	std::cout << error.what() << "\n\n";
	// }
	// try 
	// {
	// 	AForm test1("max exec",1,0);
	// 	std::cout << test1 << std::endl;
	// }
	// catch (std::exception &error) 
	// {
	// 	std::cout << error.what() << "\n\n";
	// }
	// try 
	// {
	// 	AForm test1("min exec",1,151);
	// 	std::cout << test1 << std::endl;
	// }
	// catch (std::exception &error) 
	// {
	// 	std::cout << error.what() << "\n\n";
	// }
	
}