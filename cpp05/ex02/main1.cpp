/*Generated using lboulang42's cppmain.sh*/

#include "ShrubberyCreationForm.hpp"

int main(void)
{
	{
		std::cout << "=====================" << std::endl;
		std::cout << "TEST CANONICALL CLASS" << std::endl;
		std::cout << "=====================" << std::endl;

		std::cout << "[TEST] : Default constructor" << std::endl;
		ShrubberyCreationForm a;
		std::cout << "[TEST] : Copy constructor" << std::endl;
		ShrubberyCreationForm b(a);
		std::cout << "[TEST] : Assignation operator" << std::endl;
		b = a;
		std::cout << "[TEST] : Destructor" << std::endl;
	}
	{
		std::cout << "[TEST] : ptr, new, delete, deep copy..." << std::endl;    
		ShrubberyCreationForm *d = new ShrubberyCreationForm();
		ShrubberyCreationForm *c = new ShrubberyCreationForm();
		*c = *d;
		delete c;
		delete d;
	}
}
