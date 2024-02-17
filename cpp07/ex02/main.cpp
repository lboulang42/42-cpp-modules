
#include "iter.hpp"

int main()
{
	std::cout << "TEST USING INT ARRAY" << std::endl;
	int int_array[] = {0, -1, 100000, 3 , 4};
	iter(int_array, 5, ::mysteriousfunction);
	std::cout << std::endl;
	std::cout << "TEST USING FLOAT ARRAY" << std::endl;
	float float_array[] = {0.0f, -1.1f, 10000.51f, 3.3f, 4.4f, 12};
	iter(float_array, 6, ::mysteriousfunction);
	std::cout << std::endl;
	std::cout << "TEST USING STRING ARRAY" << std::endl;
	std::string string_array[] = {"Les", "templates", "c'est", "utile"};
	iter(string_array, 4, ::mysteriousfunction);
	return 0;
}