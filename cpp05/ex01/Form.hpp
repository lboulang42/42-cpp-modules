/*Generated using lboulang42's cppmain.sh*/

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"
class Bureaucrat;

class Form
{
  	public:
		/*==========CANONICAL==========*/
		Form();
		Form(Form &src);
		Form &operator=(Form const &src);
		~Form();

		Form(std::string name, int grade_to_sign, int grade_to_execute);
		
		/*==========GETTERS==========*/
		std::string getName() const;
		bool getSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		
		/*==========EXCEPTIONS==========*/
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
	

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		/*==========OTHERS==========*/
		void beSigned(Bureaucrat &b);

	private:
		std::string const _name;
		bool _signed;
		int const _grade_to_sign;
		int const _grade_to_execute;
};

/*==========OTHER OPERATORS==========*/
std::ostream &operator<<(std::ostream &out, Form const &b);

#endif
