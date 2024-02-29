/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:06:12 by lboulang          #+#    #+#             */
/*   Updated: 2024/02/29 14:54:15 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int	main(void)
{
	{
		std::cout << "============================================" << std::endl;
		std::cout << "MAIN FROM SUBJECT" << std::endl;
		std::cout << "============================================" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	{
		std::cout << "============================================" << std::endl;
		std::cout << "MAIN FROM SUBJECT USING LIST" << std::endl;
		std::cout << "============================================" << std::endl;
		std::list<int> mstack_list;
		mstack_list.push_back(5);
		mstack_list.push_back(17);
		std::cout << mstack_list.back() << std::endl;//equivqlent of .top()
		mstack_list.pop_back();//equivalent of .pop()
		std::cout << mstack_list.size() << std::endl;
		mstack_list.push_back(3);
		mstack_list.push_back(5);
		mstack_list.push_back(737);
		mstack_list.push_back(0);
		std::list<int>::iterator it = mstack_list.begin();
		std::list<int>::iterator ite = mstack_list.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		mstack_list.sort();
		it = mstack_list.begin();
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}

	}
	return (0);
}
