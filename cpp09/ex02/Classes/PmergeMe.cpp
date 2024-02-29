/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:23:53 by lboulang          #+#    #+#             */
/*   Updated: 2024/02/29 14:40:25 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int ac, char **av)
{
	if (ac < 2)
		throw Error();
	for (int i = 1; i < ac; i++)
	{
		std::string str(av[i]);
		if (str.empty())
			continue;
		for (unsigned long j = 0; j < str.length(); j++)
		{
			if (isdigit(str[j]) == 0)
				throw Error();
		}
		long converted = FromString<long>(str);
		if (converted > 2147483647 || converted < -2147483648)
			throw Error();
		int convertedint = FromString<int>(str);
		_parsedVector.push_back(convertedint);
		_parsedDeque.push_back(convertedint);
	}
	if (_parsedVector.size() == 0)
		throw Error();
	_dequeTime = 0;
	_vectorTime = 0;
}

void PmergeMe::log(bool before)
{
	if (before)
	{
		std::cout << "Before : ";
		for (unsigned long i = 0; i < _parsedVector.size(); i++)
			std::cout << " " << _parsedVector[i];
		std::cout << std::endl;
		return ; 
	}
	std::cout << "After : ";
	for (unsigned long i = 0; i < _sortedVector.size(); i++)
		std::cout << " " << _sortedVector[i];
	std::cout << std::endl;
	std::cout << "Time to process a range of "<< _parsedVector.size() << " elements with std::vector : " << this->_vectorTime << " ms" << std::endl;
	std::cout << "Time to process a range of "<< _parsedDeque.size() << " elements with std::deque : " << this->_dequeTime << " ms" << std::endl;
}

/*vectors*/
void PmergeMe::vectorFord()
{
	std::clock_t start_vector = std::clock();
	/*check if vector already sorted*/
	if (std::adjacent_find(_parsedVector.begin(), _parsedVector.end(), std::greater<int>()) == _parsedVector.end())
	{
		_sortedVector = _parsedVector;
		return ; 
	}
	/*split vector in 2 of same size*/
	_leftVector = std::vector<int>(_parsedVector.begin(), _parsedVector.begin() + (_parsedVector.size() / 2));
	_rightVector = std::vector<int>(_parsedVector.begin() + (_parsedVector.size() / 2), _parsedVector.end());
	/*insert sort both*/
	vectorInsertSort(_leftVector, _leftVector.size());
	vectorInsertSort(_rightVector, _rightVector.size());
	/*merge*/
	vectorMerge(_leftVector.size(), _rightVector.size());
	std::clock_t end_vector = std::clock();
	this->_vectorTime = static_cast<double>(end_vector - start_vector) / CLOCKS_PER_SEC * 1000;// time in milliseconds
}

void PmergeMe::vectorMerge(int lim_part1, int lim_part2)
{
	int p1 = 0, p2 = 0;
	while (lim_part1 > p1 && lim_part2 > p2)
	{
		if (_leftVector[p1] < _rightVector[p2])
			_sortedVector.push_back(_leftVector[p1++]);
		else
			_sortedVector.push_back(_rightVector[p2++]);
	}
	while (lim_part1 > p1)
		_sortedVector.push_back(_leftVector[p1++]);
	while (lim_part2 > p2)
		_sortedVector.push_back(_rightVector[p2++]);
}

int vectorBinarySearch(std::vector<int>& vect, int item, int range_start, int range_end)
{
	if (range_end <= range_start)
	{
		if (item > vect[range_start])
			return (range_start+1);
		return (range_start);
	}
	int mid = (range_start + range_end)/2;
	if(item == vect[mid])
		return mid+1;
	if(item > vect[mid])
		return vectorBinarySearch(vect, item, mid+1, range_end);
	return vectorBinarySearch(vect, item, range_start, mid-1);
}

void vectorInsertSort(std::vector<int> &vect, int size)
{
	for (int i = 1; i < size; ++i)
	{
		int j = i - 1;
		int to_insert = vect[i];
		int index = vectorBinarySearch(vect, to_insert, 0, j);
		while (j >= index)
		{
			vect[j+1] = vect[j];
			j--;
		}
		vect[j+1] = to_insert;
	}
}

/*deque*/
void PmergeMe::dequeFord()
{
	std::clock_t start_deque = std::clock();
	/*check if deque already sorted*/
	if (std::adjacent_find(_parsedDeque.begin(), _parsedDeque.end(), std::greater<int>()) == _parsedDeque.end())
	{
		_sortedDeque = _parsedDeque;
		return ;
	}
	/*split deque in 2 of same size*/
	this->_leftDeque = std::deque<int>(_parsedDeque.begin(), _parsedDeque.begin() + (_parsedDeque.size() / 2));
	this->_rightDeque = std::deque<int>(_parsedDeque.begin() + (_parsedDeque.size() / 2), _parsedDeque.end());
	/*insert sort both*/
	dequeInsertSort(this->_leftDeque, this->_leftDeque.size());
	dequeInsertSort(this->_rightDeque, this->_rightDeque.size());
	/*merge*/
	dequeMerge();
	std::clock_t end_deque = std::clock();
	this->_dequeTime = static_cast<double>(end_deque - start_deque) / CLOCKS_PER_SEC * 1000;// time in milliseconds
}

int dequeBinarySearch(std::deque<int>& deq, int item, int range_start, int range_end)
{
	if (range_end <= range_start)
	{
		if (item > deq[range_start])
			return (range_start+1);
		return (range_start);
	}
	int mid = (range_start + range_end)/2;
	if(item == deq[mid])
		return mid+1;
	if(item > deq[mid])
		return dequeBinarySearch(deq, item, mid+1, range_end);
	return dequeBinarySearch(deq, item, range_start, mid-1);
}

void dequeInsertSort(std::deque<int> &deq, int size)
{
	for (int i = 1; i < size; ++i)
	{
		int j = i - 1;
		int to_insert = deq[i];
		int index = dequeBinarySearch(deq, to_insert, 0, j);
		while (j >= index)
		{
			deq[j+1] = deq[j];
			j--;
		}
		deq[j+1] = to_insert;
	}
}

void PmergeMe::dequeMerge(void)
{
	while (!this->_leftDeque.empty() && !this->_rightDeque.empty())
	{
		if (this->_leftDeque.front() < this->_rightDeque.front())
		{
			_sortedDeque.push_back(this->_leftDeque.front());
			this->_leftDeque.pop_front();
		}
		else
		{
			_sortedDeque.push_back(this->_rightDeque.front());
			this->_rightDeque.pop_front();
		}
	}
	while (!this->_leftDeque.empty())
	{
		_sortedDeque.push_back(this->_leftDeque.front());
		this->_leftDeque.pop_front();
	}
	while (!this->_rightDeque.empty())
	{
		_sortedDeque.push_back(this->_rightDeque.front());
		this->_rightDeque.pop_front();
	}
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &src)
{
	*this = src;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
	(void)src;
	return *this;
}

const char *PmergeMe::Error::what() const throw() { return ("\033[1;31mError\033[0m"); }