
#include "Announce.hpp"


/*not asked by subject, set color for member functions*/
void announce(std::string const &function_name, std::string const &classe)
{

    /*
    (void)function_name;
    (void)classe;
	*/
	std::string color = "\033[1;34m";
	std::string reset = "\033[0m";
	std::string func_name = function_name;
	if (function_name == classe)
	{
		color = "\033[1;32m";
		func_name += " constructor";
	}
	if (function_name[0] == '~')
	{
		color = "\033[1;31m";
		func_name += " destructor";
	}
	std::cout << color << "["<< classe << "] - " << func_name << "() called" << reset << std::endl;
}