/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:49:12 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/29 19:52:56 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Generated using lboulang42's cppmain.sh*/

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"
class Bureaucrat;

class AForm
{
  	public:
		/*==========CANONICAL==========*/
		AForm();
		AForm(AForm &src);
		AForm &operator=(AForm const &src);
		virtual ~AForm()=0;

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
		/*==========OTHERS==========*/
		void beSigned(Bureaucrat &b);

	private:
		std::string const _name;
		bool _signed;
		int const _grade_to_sign;
		int const _grade_to_execute;
};

/*==========OTHER OPERATORS==========*/
std::ostream &operator<<(std::ostream &out, AForm const &b);

#endif
