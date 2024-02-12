/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:59:00 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/31 19:03:57 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H

# include <iostream>
# include "AForm.hpp"

class AForm;

class PresidentialPardonForm : public AForm
{
    public:
        /*==========CANONICAL==========*/
        PresidentialPardonForm();
        PresidentialPardonForm(PresidentialPardonForm &src);
        ~PresidentialPardonForm();
        PresidentialPardonForm &operator=(PresidentialPardonForm const &src);
        /*constructor with name and grade*/
        PresidentialPardonForm(std::string target);
        
        /*==========GETTERS==========*/
        // std::string getTarget() const;
        
        /*==========MEMBER FUNCTIONS==========*/
        void execute(Bureaucrat const &executor) const;
    
    private:
        std::string _target;
};

#endif