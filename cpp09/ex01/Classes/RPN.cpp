/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:25:55 by lboulang          #+#    #+#             */
/*   Updated: 2024/02/23 19:56:54 by lboulang         ###   ########.fr       */
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
	std::cout <<"ARGS : " << args << std::endl;
	if (args.find_first_not_of("0123456789+-*/ ") != std::string::npos)
		throw InvalidChar();
	this->_args = args;	
}

RPN::~RPN()
{
}

void RPN::parse(void)
{
	std::cout << "Parsing" << std::endl;
	std::cout << "this->_args.length()" << this->_args.length() << std::endl;
	for (size_t i = (this->_args.length() -1); i+1 > 0; i--)
	{
		std::cout << this->_args[i] << std::endl;
		if (this->_args[i] == ' ')
			continue;
		if (isdigit(this->_args[i]))
			this->_numStack.push(this->_args[i] - '0');
		if (this->_args[i] == '+' || this->_args[i] == '-' || this->_args[i] == '*' || this->_args[i] == '/')
			this->_operatorStack.push(this->_args[i]);


	}
	std::cout << "NumStack : " << this->_numStack.size() << std::endl;
	std::cout << "OperatorStack : " << this->_operatorStack.size() << std::endl;
	if (this->_numStack.size() != this->_operatorStack.size() + 1)
		throw InvalidEquation();
	if (this->_numStack.size() < 2)
		throw InvalidEquation();
	std::cout << this->_numStack.top() << std::endl;
	std::cout << this->_operatorStack.top() << std::endl;
}

void RPN::execute(void)
{
	std::cout << "Executing" << std::endl;
	while (!this->_operatorStack.empty())
	{
		int a = this->_numStack.top();
		this->_numStack.pop();
		int b = this->_numStack.top();
		this->_numStack.pop();
		char op = this->_operatorStack.top();
		this->_operatorStack.pop();
		std::cout << "next operation : " << a << " " << op << " " << b << std::endl;
		if (op == '+')
			this->_numStack.push(a + b);
		if (op == '-')
			this->_numStack.push(a - b);
		if (op == '*')
			this->_numStack.push(a * b);
		if (op == '/')
			this->_numStack.push(a / b);
		std::cout << "NumStack : " << this->_numStack.top() << std::endl;
	}
	std::cout << "Result : " << this->_numStack.top() << std::endl;
	std::cout << "NumStack : " << this->_numStack.size() << std::endl;

}