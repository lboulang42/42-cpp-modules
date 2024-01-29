/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:55:56 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/29 19:56:39 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
class AForm;

class RobotomyRequestForm : public AForm
{
    public:
        /*==========CANONICAL==========*/
        RobotomyRequestForm();
        RobotomyRequestForm(RobotomyRequestForm &src);
        RobotomyRequestForm &operator=(RobotomyRequestForm const &src);
        ~RobotomyRequestForm();
        /*constructor with name and grade*/
        RobotomyRequestForm(std::string target);
        
        /*==========GETTERS==========*/
        std::string getTarget() const;
        
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
        void execute(Bureaucrat const &executor) const;
    
    private:
        std::string const _target;
};


#endif