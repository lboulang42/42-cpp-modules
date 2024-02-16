/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:51:11 by lboulang          #+#    #+#             */
/*   Updated: 2024/02/16 11:51:13 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <fstream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
  	public:
		/*==========CANONICAL==========*/
		/*default constructor*/
		AForm();
		/*copy constructor*/
		AForm(AForm &src);
		/*operator = */
		AForm &operator=(AForm const &src);
		/*destructor*/
		virtual ~AForm();

		/*==========OTHER CONSTRUCTOR==========*/
		AForm(std::string name, int grade_to_sign, int grade_to_execute);
		
		/*==========GETTERS==========*/
		std::string getName() const;
		bool getSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		
		/*==========MEMBER FUNCTIONS==========*/
		void beSigned(const Bureaucrat &b);
		virtual void execute (Bureaucrat const & executor) const = 0;

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

	private:
		std::string const _name;
		bool _signed;
		int const _grade_to_sign;
		int const _grade_to_execute;
};

/*==========OTHER OPERATORS==========*/
std::ostream &operator<<(std::ostream &out, AForm const &b);

#endif
