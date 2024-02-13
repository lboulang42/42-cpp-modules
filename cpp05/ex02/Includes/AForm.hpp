/*Generated using lboulang42's cppmain.sh*/

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
// # include <string>
// # include <exception>
// # include <stdexcept>
// # include <exception>
# include <fstream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
  	public:
		/*==========CANONICAL==========*/
		AForm();
		AForm(AForm &src);
		AForm &operator=(AForm const &src);
		virtual ~AForm();

		AForm(std::string name, int grade_to_sign, int grade_to_execute);
		
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
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		/*==========OTHERS==========*/
		void beSigned(const Bureaucrat &b);
		virtual void execute (Bureaucrat const & executor) const = 0;

	private:
		std::string const _name;
		bool _signed;
		int const _grade_to_sign;
		int const _grade_to_execute;
};

/*==========OTHER OPERATORS==========*/
std::ostream &operator<<(std::ostream &out, AForm const &b);

#endif
