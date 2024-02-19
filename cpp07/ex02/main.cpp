
#include "Array.hpp"

int main()
{
	try
	{
		Array <int> a;
		std::cout << "Array of 0 int" << std::endl;
		std::cout << "Before : \n" << a << std::endl;
		std::cout << "try to assign at index 0 : " << std::endl;
		a[0] = 1;
		std::cout << "After : \n" << a << std::endl << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{


		std::cout << std::endl << "Array of 5 int";
		Array<int> a(5);
		std::cout << std::endl << "Before : \n" << a << std::endl;
		a[0] = 1;
		a[1] = 2;
		a[2] = 3;
		a[3] = 4;
		a[4] = 5;
		std::cout << "After : \n" << a << std::endl << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Array<float> a(5);
		std::cout << std::endl << "Array of 5 float";
		std::cout << std::endl << "Before : \n" << a << std::endl;
		a[0] = 1.1;
		a[1] = 2.2;
		a[2] = 3.3;
		a[3] = 4.4;
		a[4] = 5.5;
		std::cout << "After : \n" << a << std::endl << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Array<std::string> a(2);
		std::cout << std::endl << "Array of 2 string ";
		std::cout << std::endl << "Before : \n" << a << std::endl;
		a[0] = "hello";
		a[1] = "world";
		std::cout << "After : \n" << a << std::endl << std::endl;
		std::string tmp = a[1];
		a[1] = a[0];
		a[0] = tmp;
		std::cout << "After swap : \n" << a << std::endl << std::endl;
		Array <std::string> b(a);
		std::cout << "After copy : \n" << b << std::endl << std::endl;
		Array <std::string> c(4);
		c[0] ="string0";
		c[1] ="string1";
		c[2] ="string2";
		c[3] ="string3";
		std::cout << "Before operator = : \n" << c << std::endl << std::endl;
		c = a;
		std::cout << "After operator = : \n" << c << std::endl << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}
	return 0;
}