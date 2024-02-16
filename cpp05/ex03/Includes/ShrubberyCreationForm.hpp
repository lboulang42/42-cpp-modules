/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:48:50 by lboulang          #+#    #+#             */
/*   Updated: 2024/02/16 11:42:37 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H

#include "AForm.hpp"

class AForm;

class ShrubberyCreationForm : public AForm
{
    public:
        /*==========CANONICAL==========*/
        /*default constructor*/
        ShrubberyCreationForm();
        /*copy constructor*/
        ShrubberyCreationForm(ShrubberyCreationForm const &src);
        /*operator = */
        ShrubberyCreationForm &operator=(ShrubberyCreationForm const &src);
        /*destructor*/
        ~ShrubberyCreationForm();
        
        /*==========OTHER CONSTRUCTOR==========*/
        ShrubberyCreationForm(std::string const &target);
        
        /*==========MEMBER FUNCTIONS==========*/
        virtual void execute(Bureaucrat const &executor) const;
    
    private:
        std::string _target;
};


#endif