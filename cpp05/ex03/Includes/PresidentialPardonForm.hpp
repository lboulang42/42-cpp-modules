/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:45:43 by lboulang          #+#    #+#             */
/*   Updated: 2024/02/16 11:38:17 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H

# include <iostream>
# include "AForm.hpp"

class Aform;

class PresidentialPardonForm : public AForm
{
    public:
        /*==========CANONICAL==========*/
        /*default constructor*/
        PresidentialPardonForm();
        /*copy constructor*/
        PresidentialPardonForm(PresidentialPardonForm const &src);
        /*operator = */
        PresidentialPardonForm &operator=(PresidentialPardonForm const &src);
        /*destructor*/
        ~PresidentialPardonForm();
        
        /*==========OTHER CONSTRUCTOR==========*/
        PresidentialPardonForm(std::string const &target);
        
        /*==========MEMBER FUNCTIONS==========*/
        virtual void execute(Bureaucrat const &executor) const;

    private:
        std::string _target;
};

#endif