/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:14:34 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/29 19:43:57 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

# include "Form.hpp"

class Form;

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
		
		/*==========OPERATORS==========*/
		Bureaucrat operator++(void);
		Bureaucrat operator--(void);
		
		/*==========GETTERS==========*/
		std::string getName() const;
		int getGrade() const;
		
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
		/*==========OTHERS==========*/
		void signForm(Form &f);
		
	
	private:
		const std::string _name;
		int _grade;
};

/*==========OTHER OPERATORS==========*/
std::ostream &operator<<(std::ostream &out, Bureaucrat const &b);
#endif