/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:07:18 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/10 14:40:26 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

class Harl
{
  private:
	std::string level_tab[4];
	void (Harl::*complain_ptr[4])();
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
	void nothing(void);
	int filter;

  public:
	void set_filter(char *av1);
	void fullcomplain(void);
	Harl();
	~Harl();
};

#endif