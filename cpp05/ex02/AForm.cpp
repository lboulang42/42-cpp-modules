/*Generated using lboulang42's cppmain.sh*/

#include "AForm.hpp"


/*==========CANONICAL==========*/

/*default constructor*/
AForm::AForm() : _name("Default"), _signed(false), _grade_to_sign(1), _grade_to_execute(1)
{
	std::cout << "[AForm] - ";
	std::cout << "Default constructor called" << std::endl;
}

AForm::AForm(std::string name, int grade_to_sign, int grade_to_execute) : _name(name), _signed(false), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute)
{
	std::cout << "[AForm] - ";
	std::cout << "Constructor with name and grade called" << std::endl;
	if (grade_to_sign < 1 || grade_to_execute < 1)
		throw AForm::GradeTooHighException();
	else if (grade_to_sign > 150 || grade_to_execute > 150)
		throw AForm::GradeTooLowException();
}

/*copy constructor*/
AForm::AForm(AForm &src) : _name(src.getName()), _signed(false), _grade_to_sign(src.getGradeToSign()), _grade_to_execute(src.getGradeToExecute())
{
	std::cout << "[AForm] - ";
	std::cout << "Copy constructor called" << std::endl;
}

/*operator = */
AForm &AForm::operator=(AForm const &src)
{
	std::cout << "[AForm] - ";
	std::cout << "Assignation operator called" << std::endl;
	if (this != &src)
	{
		*this = src;
	}
	return (*this);
}

AForm::~AForm()
{
	std::cout << "[AForm] - ";
	std::cout << "Destructor called" << std::endl;
}

/*==========GETTERS==========*/
std::string AForm::getName() const
{
	return (this->_name);
}

bool AForm::getSigned() const
{
	return (this->_signed);
}

int AForm::getGradeToSign() const
{
	if (this->_grade_to_sign < 1)
		throw AForm::GradeTooHighException();
	else if (this->_grade_to_sign > 150)
		throw AForm::GradeTooLowException();	
	return (this->_grade_to_sign);
}

int AForm::getGradeToExecute() const
{
	if (this->_grade_to_execute < 1)
		throw AForm::GradeTooHighException();
	else if (this->_grade_to_execute > 150)
		throw AForm::GradeTooLowException();
	return (this->_grade_to_execute);
}
/*==========SETTER==========*/
		
//void AForm::set(std::string &s)
//{
//	std::cout << "[AForm] - ";
//	std::cout << "setter called" << std::endl;
//	this->_var_str = s;
//}

/*==========EXCEPTIONS==========*/

 
const char *AForm::GradeTooHighException::what() const throw()
{
	return ("\e[0;35m[AForm::GradeTooHighException] - GRADE TOO HIGH\033[0m");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("\e[0;35m[AForm::GradeTooLowException] - GRADE TOO LOW\033[0m");
}

/*==========OTHER OPERATORS==========*/
std::ostream &operator<<(std::ostream &out, AForm const &b)
{
	out << b.getName() << ", AForm grade to sign " << b.getGradeToSign() << ", AForm grade to execute " << b.getGradeToExecute() << "." << std::endl;
	return (out);
}

void AForm::beSigned(Bureaucrat &b)
{
	b.signForm(*this);	
	if (b.getGrade() <= this->_grade_to_sign)
	{
		this->_signed = true;
	}
	else
		throw AForm::GradeTooLowException();
}