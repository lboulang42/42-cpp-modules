/*Generated using lboulang42's cppmain.sh*/

#include "ShrubberyCreationForm.hpp"

/*==========CANONICAL==========*/

/*default constructor*/
ShrubberyCreationForm::ShrubberyCreationForm()
{
	std::cout << "[ShrubberyCreationForm] - ";
	std::cout << "Default constructor called" << std::endl;
	//this->_var_str = "default";
	//this->_var_int = 0;
}

/*copy constructor*/
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &src)
{
	std::cout << "[ShrubberyCreationForm] - ";
	std::cout << "Copy constructor called" << std::endl;
	(void)src;
	//this->_var_str = src.get();
}

/*operator = */
ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src)
{
	std::cout << "[ShrubberyCreationForm] - ";
	std::cout << "Assignation operator called" << std::endl;
	(void)src;
	if (this != &src)
	{
		//this->_var_str = src.get();
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "[ShrubberyCreationForm] - ";
	std::cout << "Destructor called" << std::endl;
}

/*==========OPERATORS==========*/

//ShrubberyCreationForm ShrubberyCreationForm::operator++(void)
//{
//	std::cout << "[ShrubberyCreationForm] - ";
//	std::cout << "Operator ++ called" << std::endl;
//	this->_var_int++;
//	return (*this);
//}

//ShrubberyCreationForm ShrubberyCreationForm::operator--(void)
//{
//	std::cout << "[ShrubberyCreationForm] - ";
//	std::cout << "Operator -- called" << std::endl;
//	this->_var_int--;
//	return (*this);
//}

/*==========GETTERS==========*/

//std::string ShrubberyCreationForm::get() const
//{
//	std::cout << "[ShrubberyCreationForm] - ";
//	std::cout << "Function get called" << std::endl;
//	return (this->_var_str);
//}

/*==========SETTER==========*/
		
//void ShrubberyCreationForm::set(std::string &s)
//{
//	std::cout << "[ShrubberyCreationForm] - ";
//	std::cout << "setter called" << std::endl;
//	this->_var_str = s;
//}

/*==========EXCEPTIONS==========*/

//const char *ShrubberyCreationForm::ExceptionName::what() const throw()
//{
//	return ("[EXCEPTION] - ExceptionName");
//}


/*==========OTHER OPERATORS==========*/
//std::ostream &operator<<(std::ostream &out, ShrubberyCreationForm const &b)
//{
//	std::cout << "[ShrubberyCreationForm] - ";
//	std::cout << "Operator << called" << std::endl;
//	out << b.get() << std::endl;
// return (out);
//}
 
