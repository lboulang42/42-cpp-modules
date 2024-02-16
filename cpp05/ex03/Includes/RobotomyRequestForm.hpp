/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:47:54 by lboulang          #+#    #+#             */
/*   Updated: 2024/02/16 11:40:39 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H

#include <cstdlib>

# include "AForm.hpp"

class AForm;

class RobotomyRequestForm : public AForm
{
    public:
        /*==========CANONICAL==========*/
        /*default constructor*/
        RobotomyRequestForm();
        /*copy constructor*/
        RobotomyRequestForm(RobotomyRequestForm const &src);
        /*operator = */
        RobotomyRequestForm &operator=(RobotomyRequestForm const &src);
        /*destructor*/
        ~RobotomyRequestForm();
        
        /*==========OTHER CONSTRUCTOR==========*/
        RobotomyRequestForm(std::string const &target);
        
        /*==========MEMBER FUNCTIONS==========*/
        virtual void execute(Bureaucrat const &executor) const;

    private:
        std::string _target;
}; 


#endif