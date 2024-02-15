/*Generated using lboulang42's cppmain.sh*/

#include "ScalarConverter.hpp"

/*==========CANONICAL==========*/

/*default constructor*/
ScalarConverter::ScalarConverter(void)
{
	std::cout << "[ScalarConverter] - ";
	std::cout << "Default constructor called" << std::endl;
}

/*copy constructor*/
ScalarConverter::ScalarConverter(ScalarConverter &src)
{
	std::cout << "[ScalarConverter] - ";
	std::cout << "Copy constructor called" << std::endl;
	this->_originalStr = src._originalStr;
	this->_type = src._type;
}

/*operator = */
ScalarConverter &ScalarConverter::operator=(ScalarConverter const &src)
{
	std::cout << "[ScalarConverter] - ";
	std::cout << "Assignation operator called" << std::endl;
	if (this != &src)
	{
		this->_originalStr = src._originalStr;
		this->_type = src._type;
	}
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "[ScalarConverter] - ";
	std::cout << "Destructor called" << std::endl;
}

/*==========OTHER CONSTRUCTORS==========*/

ScalarConverter::ScalarConverter(std::string const &str)
{
	std::cout << "[ScalarConverter] - ";
	std::cout << "Constructor called" << std::endl;
	if (str.empty())
	{
		std::cout << "Error: empty string" << std::endl;
		return ;
	}
	this->_originalStr = str;
	if (isSpecialCase(this->_originalStr))
		return ; 
	this->_type = getType(this->_originalStr);
	convert(this->_originalStr);
}

/*==========EXCEPTIONS==========*/

//const char *ScalarConverter::ExceptionName::what() const throw()
//{
//	return ("[EXCEPTION] - ExceptionName");
//}


/*==========OTHER OPERATORS==========*/
//std::ostream &operator<<(std::ostream &out, ScalarConverter const &b)
//{
//	std::cout << "[ScalarConverter] - ";
//	std::cout << "Operator << called" << std::endl;
//	out << b.get() << std::endl;
// return (out);
//}




void ScalarConverter::convert(std::string const &str)
{

}

/*

bool ScalarConverter::isInt ( void )
{
    char *fin;
	long nb = std::strtol(this->_str.c_str(), &fin, 10);
	
	if (nb >= INT_MIN && nb <= INT_MAX)
		this->_overflow = false;
	else
		this->_overflow = true;
	if (*fin == '\0' && this->_str.size() > 0)
		return true;
	return false;
}

bool ScalarConverter::isDouble ( void )
{
	char* fin;
	const char *point = std::strchr(this->_str.c_str(), '.');
	int start = (this->_str[0] == '+' || this->_str[0] == '-') ? 1 : 0;

	std::strtod(this->_str.c_str(), &fin);
    if (*fin == '\0' && point != NULL && std::isdigit(this->_str[start]))
	{
		if (point != NULL && std::isdigit(*(point + 1)) && this->_str.size() > 1)
			return true;
	}
	return false;
}

bool ScalarConverter::isChar ( void )
{
	if (this->_str.size() == 1)
		return true;
	return false;
}





*/

bool isFloat(std::string const &str)
{
	
}

bool isChar ( std::string const &str )
{

}

bool isDouble ( std::string const &str )
{

}

bool isInt ( std::string const &str )
{

}



std::string getType(std::string const &str)
{
	if (isFloat(str))
		return ("float");
	if (isChar(str))
		return ("char");
	if (isDouble(str))
		return ("double");
	if (isInt(str))
		return ("int");
	return (NULL);
}

/*
- `nanf`: This stands for "Not a Number" float. It is a special value that represents a result that is undefined or unrepresentable. For example, the square root of a negative number.
- `-inff` and `+inff`: These stand for negative infinity and positive infinity float respectively. They are used to represent values that are beyond the limit of floating point numbers in the negative and positive direction. For example, dividing a positive float by zero results in `+inff`, and dividing a negative float by zero results in `-inff`.
*/

bool isSpecialCase(std::string const &str)
{
	if (str == "inf" || str == "inff")
	{
		std::cout << "char : impossible\n";
		std::cout << "int : impossible\n";
		std::cout << "float : inff\n";
		std::cout << "double : inf\n";
		return (true); 
	}
	if (str == "+inff" || str == "+inf")
	{
		std::cout << "char : impossible\n";
		std::cout << "int : impossible\n";
		std::cout << "float : +inff\n";
		std::cout << "double : +inf\n";
		return (true); 
	}
	if (str == "-inff" || str == "-inf")
	{
		std::cout << "char : impossible\n";
		std::cout << "int : impossible\n";
		std::cout << "float : -inff\n";
		std::cout << "double : -inf\n";
		return (true); 
	}
	if (str == "nanf" || str == "nan")
	{
		std::cout << "char : impossible\n";
		std::cout << "int : impossible\n";
		std::cout << "float : nanf\n";
		std::cout << "double : nan\n";
		return (true); 
	}
	return (false);
}

