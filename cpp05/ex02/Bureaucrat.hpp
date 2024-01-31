/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:14:34 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/31 18:54:43 by lboulang         ###   ########.fr       */
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
		Bureaucrat();
		Bureaucrat(Bureaucrat &src);
		Bureaucrat &operator=(Bureaucrat const &src);
		~Bureaucrat();
		
		/*constructor with name and grade*/
		Bureaucrat(const std::string name, int grade);
		
		/*==========GETTERS==========*/
		std::string getName() const;
		int getGrade() const;
		
		/*==========MEMBER FUNCTIONS==========*/
		void incrementGrade();
		void decrementGrade();
		void signForm(AForm &AForm);
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