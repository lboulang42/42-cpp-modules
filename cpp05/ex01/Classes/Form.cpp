/*Generated using lboulang42's cppmain.sh*/

#include "Form.hpp"


/*==========CANONICAL==========*/

/*default constructor*/
Form::Form() : _name("Default"), _signed(false), _grade_to_sign(1), _grade_to_execute(1)
{
	std::cout << "[Form] - ";
	std::cout << "Default constructor called" << std::endl;
}

/*copy constructor*/
Form::Form(Form &src) : _name(src.getName()), _signed(src.getSigned()), _grade_to_sign(src.getGradeToSign()), _grade_to_execute(src.getGradeToExecute())
{
	std::cout << "[Form] - ";
	std::cout << "Copy constructor called" << std::endl;
	if (_grade_to_sign < 1 || _grade_to_execute < 1)
		throw Form::GradeTooHighException();
	else if (_grade_to_sign > 150 || _grade_to_execute > 150)
		throw Form::GradeTooLowException();
}

/*operator = */
Form &Form::operator=(Form const &src)
{
	std::cout << "[Form] - ";
	std::cout << "Assignation operator called" << std::endl;
	if (this != &src)
		*this = src;
	this->_signed = src.getSigned();
	return (*this);
}

/*destructor*/
Form::~Form()
{
	std::cout << "[Form] - ";
	std::cout << "Destructor called" << std::endl;
}

/*==========OTHER CONSTRUCTOR==========*/
Form::Form(std::string name, int grade_to_sign, int grade_to_execute) : _name(name), _signed(false), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute)
{
	std::cout << "[Form] - ";
	std::cout << "Constructor with name and grade called" << std::endl;
	if (grade_to_sign < 1 || grade_to_execute < 1)
		throw Form::GradeTooHighException();
	else if (grade_to_sign > 150 || grade_to_execute > 150)
		throw Form::GradeTooLowException();
}

/*==========GETTERS==========*/
std::string Form::getName() const
{
	return (this->_name);
}

bool Form::getSigned() const
{
	return (this->_signed);
}

int Form::getGradeToSign() const
{
	if (this->_grade_to_sign < 1)
		throw Form::GradeTooHighException();
	else if (this->_grade_to_sign > 150)
		throw Form::GradeTooLowException();	
	return (this->_grade_to_sign);
}

int Form::getGradeToExecute() const
{

	if (this->_grade_to_execute < 1)
		throw Form::GradeTooHighException();
	else if (this->_grade_to_execute > 150)
		throw Form::GradeTooLowException();
	return (this->_grade_to_execute);
}

/*==========MEMBER FUNCTIONS==========*/
void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() <= this->_grade_to_sign)
		this->_signed = true;
	else
		throw Form::GradeTooLowException();
}

/*==========EXCEPTIONS==========*/
const char *Form::GradeTooHighException::what() const throw()
{
	return ("\e[0;35m[Form::GradeTooHighException] - GRADE TOO HIGH\033[0m");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("\e[0;35m[Form::GradeTooLowException] - GRADE TOO LOW\033[0m");
}

/*==========OTHER OPERATORS==========*/
std::ostream &operator<<(std::ostream &out, Form const &b)
{
	out << b.getName() << ", form grade to sign " << b.getGradeToSign() << ", form grade to execute " << b.getGradeToExecute();
	return (out);
}

