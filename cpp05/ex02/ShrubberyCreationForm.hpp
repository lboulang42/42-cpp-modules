/*Generated using lboulang42's cppmain.sh*/

#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H


# include <iostream>

# include "AForm.hpp"
class AForm;

class ShrubberyCreationForm : public AForm
{
  	public:
		/*==========CANONICAL==========*/
		ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm &src);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &src);
		~ShrubberyCreationForm();
		
		/*==========OPERATORS==========*/
		//ShrubberyCreationForm operator++(void);
		//ShrubberyCreationForm operator--(void);
		
		/*==========GETTERS==========*/
		//std::string get() const;
		
		/*==========SETTER==========*/
		//void set(std::string &s);
		
		/*==========EXCEPTIONS==========*/
		//class ExceptionName : public std::exception
		//{
		//	public:
		//		virtual const char *what() const throw();
		//};
	
};

// /*==========OTHER OPERATORS==========*/
// std::ostream &operator<<(std::ostream &out, ShrubberyCreationForm const &b);

#endif
