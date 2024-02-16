/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:14:34 by lboulang          #+#    #+#             */
/*   Updated: 2024/02/16 11:33:51 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <iostream>

# include "AForm.hpp"

class AForm;

class Bureaucrat
{
	public:
		/*==========CANONICAL==========*/
		/*default constructor*/
		Bureaucrat();
		/*copy constructor*/
		Bureaucrat(Bureaucrat &src);
		/*operator = */
		Bureaucrat &operator=(Bureaucrat const &src);
		/*destructor*/
		~Bureaucrat();
		
		/*==========OTHER CONSTRUCTOR==========*/
		Bureaucrat(const std::string name, int grade);
		
		/*==========GETTERS==========*/
		std::string getName() const;
		int getGrade() const;
		
		/*==========MEMBER FUNCTIONS==========*/
		void incrementGrade();
		void decrementGrade();
		void signForm(AForm &form);
		void executeForm(AForm const &form);

		/*==========EXCEPTIONS==========*/
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
	
	private:
		const std::string _name;
		int _grade;
};

/*==========OTHER OPERATORS==========*/
std::ostream &operator<<(std::ostream &out, Bureaucrat const &b);

#endif