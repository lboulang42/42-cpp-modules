/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:10:55 by lboulang          #+#    #+#             */
/*   Updated: 2023/12/30 17:38:39 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <sstream>
# include <stdlib.h>
/*
◦ Un contact possède les champs suivants : first name (prénom), last name
(nom de famille), nickname (surnom), phone number (numéro de téléphone),
et darkest secret (son plus lourd secret). Les champs d’un contact enregistré ne
peuvent être vides.

*/
class Contact
{
  private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone;
	std::string secret;
  public:
	Contact();
	~Contact();
    
	int Add();
	
    void ClearField();
	void Show(int index);
	void ShowLine();
	
    std::string AddField(std::string name);
	std::string Display(std::string);
};

#endif