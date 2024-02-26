/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:05:23 by lboulang          #+#    #+#             */
/*   Updated: 2024/02/26 18:11:51 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>
#include <ctime>

class PmergeMe
{
	public:
		PmergeMe(int ac, char **av);
		~PmergeMe();
		PmergeMe(const PmergeMe &src);
		PmergeMe &operator=(const PmergeMe &src);
		
		/*vector*/
		void vectorFord();
		void vectorMerge(int lim_part1, int lim_part2);
		/*deque*/
		void dequeFord();        
		void dequeMerge(void);
		
		class Error : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("\033[1;31mError\033[0m");
				}
		};
		
		void log(bool before);
		
	private:
		std::vector<int> _parsedVector;
		std::vector<int> _leftVector;
		std::vector<int> _rightVector;
		std::vector<int> _sortedVector;
		std::deque<int> _parsedDeque;
		std::deque<int> _leftDeque;
		std::deque<int> _rightDeque;
		std::deque<int> _sortedDeque;
		double _vectorTime;
		double _dequeTime;
};

int  dequeBinarySearch(std::deque<int>& arr, int item, int low, int high);
void dequeInsertSort(std::deque<int> &arr, int n);

void vectorInsertSort(std::vector<int> &arr, int n);

template<typename T>
T FromString(const std::string& str)
{
	std::istringstream is(str);
	T t;
	is >> t;
	return t;
}

#endif