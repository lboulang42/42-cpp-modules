/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:25:55 by lboulang          #+#    #+#             */
/*   Updated: 2024/02/26 11:55:12 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(int ac, char **av)
{
	if (ac != 2)
		throw ArgsNumber();
	std::string args = av[1];
	if (args.empty())
		throw ArgsEmpty();
	if (args.find_first_not_of("0123456789+-*/ ") != std::string::npos)
		throw InvalidChar();
	this->_args = args;	
}

RPN::~RPN()
{
}

RPN::RPN()
{
}

RPN::RPN(const RPN &src)
{
	*this = src;
}

RPN &RPN::operator=(const RPN &src)
{
	if (this != &src)
		this->_args = src._args;
	return (*this);
}

void RPN::parse(void)
{
	int count_num = 0;
	int count_op = 0;
	for (size_t i = (this->_args.length() -1); i+1 > 0; i--)
	{
		if (this->_args[i] == ' ')
			continue;
		if (isdigit(this->_args[i]) || this->_args[i] == '+' || this->_args[i] == '-' || this->_args[i] == '*' || this->_args[i] == '/')
		{
			if (isdigit(this->_args[i]))
			{
				this->_onestack.push(this->_args[i] - '0');
				count_num++;
			}
			if (this->_args[i] == '+' || this->_args[i] == '-' || this->_args[i] == '*' || this->_args[i] == '/')
			{
				this->_onestack.push(this->_args[i]);
				count_op++;			
			}
		}
	}
	if (count_num <= count_op)
		throw InvalidEquation();
}

void RPN::execute(void)
{
	while (!this->_onestack.empty())
	{
		int currenttop = this->_onestack.top();
		this->_onestack.pop();
		if (currenttop == '+' || currenttop == '-' || currenttop == '*' || currenttop == '/')
		{
			if (this->_operationstack.size() < 2)
				throw InvalidEquation();
			int a = this->_operationstack.top();
			this->_operationstack.pop();
			int b = this->_operationstack.top();
			this->_operationstack.pop();
			if (currenttop == '+')
				this->_operationstack.push(b +a);
			if (currenttop == '-')
				this->_operationstack.push(b -a);
			if (currenttop == '*')
				this->_operationstack.push(b *a);
			if (currenttop == '/')
				this->_operationstack.push(b / a);
		}
		else
			this->_operationstack.push(currenttop);
	}
	std::cout << this->_operationstack.top() << std::endl;
}
