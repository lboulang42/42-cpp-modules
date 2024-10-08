/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:51:49 by lboulang          #+#    #+#             */
/*   Updated: 2024/02/16 11:51:51 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"
class Bureaucrat;

class Form
{
  	public:
		/*==========CANONICAL==========*/
		/*default constructor*/
		Form();
		/*copy constructor*/
		Form(Form &src);
		/*operator = */
		Form &operator=(Form const &src);
		/*destructor*/
		~Form();

		/*==========OTHER CONSTRUCTOR==========*/
		Form(std::string name, int grade_to_sign, int grade_to_execute);
		
		/*==========GETTERS==========*/
		std::string getName() const;
		bool getSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		
		/*==========MEMBER FUNCTIONS==========*/
		void beSigned(const Bureaucrat &b);

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

	private:
		std::string const _name;
		bool _signed;
		int const _grade_to_sign;
		int const _grade_to_execute;
};

/*==========OTHER OPERATORS==========*/
std::ostream &operator<<(std::ostream &out, Form const &b);

#endif
