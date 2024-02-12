/*Generated using lboulang42's cppmain.sh*/

#include "ScalarConverter.hpp"

int main(void)
{
	{
		std::cout << "=====================" << std::endl;
		std::cout << "TEST CANONICALL CLASS" << std::endl;
		std::cout << "=====================" << std::endl;

		std::cout << "[TEST] : Default constructor" << std::endl;
		ScalarConverter a;
		std::cout << "[TEST] : Copy constructor" << std::endl;
		ScalarConverter b(a);
		std::cout << "[TEST] : Assignation operator" << std::endl;
		b = a;
		std::cout << "[TEST] : Destructor" << std::endl;
	}
	{
		std::cout << "[TEST] : ptr, new, delete, deep copy..." << std::endl;    
		ScalarConverter *d = new ScalarConverter();
		ScalarConverter *c = new ScalarConverter();
		*c = *d;
		delete c;
		delete d;
	}
}
