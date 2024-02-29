/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:25:36 by lboulang          #+#    #+#             */
/*   Updated: 2024/02/29 14:28:05 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>

#include <string.h>
#include <stack>

class RPN
{
	public:
		RPN(int ac, char **av);
		~RPN();
		void parse(void);
		void execute(void);
		class InvalidChar : public std::exception { public: virtual const char* what() const throw(); };
		class ArgsNumber : public std::exception { public: virtual const char* what() const throw(); };
		class ArgsEmpty : public std::exception { public: virtual const char* what() const throw(); };
		class InvalidEquation : public std::exception { public: virtual const char* what() const throw(); };

		
	private:
		RPN();
		RPN(RPN const &src);
		RPN &operator=(RPN const &rhs);
		std::string _args;
		std::stack<int> _onestack;
		std::stack<int> _operationstack;
};


#endif