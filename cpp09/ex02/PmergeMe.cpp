/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 22:42:59 by ofadhel           #+#    #+#             */
/*   Updated: 2024/08/16 18:11:18 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(std::deque<int> d, std::vector<int> v)
{
	_d = d;
	_v = v;
	_straggler = -1; //used like a flag if the sequence is odd
	printDeque("Before: ");
}

PmergeMe::PmergeMe(PmergeMe const &src)
{
	*this = src;
}

PmergeMe::~PmergeMe()
{
}

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs)
{
	if (this != &rhs)
	{
		this->_d = rhs._d;
		this->_v = rhs._v;
	}
	return *this;
}

//methods

template <typename T>
T PmergeMe::jacobsthalSequenceD(int n)
{
	T jacobsthal;
	jacobsthal.push_back(0);
	jacobsthal.push_back(1);

	int i = 2;
	while (1)
	{
		if ((jacobsthal[i - 1] + 2 * jacobsthal[i - 2]) > n)
			break;
		jacobsthal.push_back(jacobsthal[i - 1] + 2 * jacobsthal[i - 2]);
		i++;
	}
	jacobsthal.push_back(n);
	return jacobsthal;
}

template <typename T>
T PmergeMe::insertSequence(T jacobsthal, int size)
{
	T insertionSequence;

	for (int i = 1; i < size; i++) {
		int current = jacobsthal[i];
		while (current > jacobsthal[i - 1])
		{	// Insert all values between current and previous
			insertionSequence.push_back(current - 1);
			current--;
		}
	}
	return insertionSequence;
}

template <typename T>
void PmergeMe::binaryInsert(T &main, int value)
{
	typename T::iterator it = std::lower_bound(main.begin(), main.end(), value);
	main.insert(it, value);
}

void PmergeMe::printDeque(std::string const str)
{
	std::cout << str;
	for (std::deque<int>::iterator it = _d.begin(); it != _d.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

// Deque

void PmergeMe::recursionSort(std::deque<std::pair<int, int> > &pairs)
{
	for (size_t i = 0; i < _d.size(); i += 2)
		pairs.push_back(std::make_pair(_d[i], _d[i + 1]));
	_d.clear();

	//check last pair
	if (pairs.size() == 1)
	{
		if (pairs[0].first > pairs[0].second)
			std::swap(pairs[0].first, pairs[0].second);
		_d.push_back(pairs[0].first);
		_d.push_back(pairs[0].second);
		return;
	}

	//order the pairs
	for (std::deque<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
	{
		if (it->first > it->second)
			std::swap(it->first, it->second);
	}
	std::deque<std::pair<int, int> > new_pairs;

	if (pairs.size() % 2 != 0)
	{
		for (size_t i = 0; i < pairs.size() - 1; i += 2)
			new_pairs.push_back(std::make_pair(pairs[i].second, pairs[i + 1].second));
		new_pairs.push_back(std::make_pair(pairs[pairs.size() - 1].first, pairs[pairs.size() - 1].second));
		pairs.erase(pairs.end() - 1);
	}
	else
	{
		for (size_t i = 0; i < pairs.size(); i += 2)
			new_pairs.push_back(std::make_pair(pairs[i].second, pairs[i + 1].second));
	}

	recursionSort(new_pairs);

	std::deque<int> pend;
	for (std::deque<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
		pend.push_back(it->first);


	std::deque<int> jacobsthal = jacobsthalSequenceD<std::deque<int> >(pend.size());
	std::deque<int> insertionSequence = insertSequence(jacobsthal, jacobsthal.size());
	
	for (size_t i = 0; i < pend.size(); i++)
		binaryInsert(_d, pend[insertionSequence[i]]);
}

void PmergeMe::start()
{
	//0. start timer
	std::clock_t start_d = std::clock();

	//1. first check if the deque is even or odd.  If odd, remove the last element and call it straggler
	if (_d.size() % 2 != 0)
	{
		_straggler = _d.back();
		_d.pop_back();
	}

	//2. Now we can start creating pairs
	std::deque<std::pair<int, int> > pairs;


	recursionSort(pairs);

	if (_straggler != -1)
		binaryInsert(_d, _straggler);

	//end timer
	std::clock_t end_d = std::clock();
	/*clock() returns the processor time consumed by the program. The result is in clock ticks.
	CLOCKS_PER_SEC is the number of clock ticks per second, used to convert the clock ticks into seconds.*/

	double process_time_deque = static_cast<double>(end_d - start_d) / CLOCKS_PER_SEC * 1000; //* 10.... convert to milliseconds

	printDeque("After: ");
	startVector(); //now do the same with vector
	std::cout << "Time to process a range of " << _d.size() << " elements with std::deque: " << std::fixed << process_time_deque << "ms" << std::endl;

}

void PmergeMe::startVector()
{
	std::clock_t start_v = std::clock();

	if (_v.size() % 2 != 0)
	{
		_straggler = _v.back();
		_v.pop_back();
	}

	std::vector<std::pair<int, int> > pairs;

	recursionSortv(pairs);

	if (_straggler != -1)
		binaryInsert(_v, _straggler);

	std::clock_t end_v = std::clock();
	double process_time_vector = double(end_v - start_v) / CLOCKS_PER_SEC * 1000;

	std::cout << "Time to process a range of " << _v.size() << " elements with std::vector: " << std::fixed << process_time_vector << "ms" << std::endl;
}

void PmergeMe::recursionSortv(std::vector<std::pair<int, int> > &pairs)
{
	for (size_t i = 0; i < _v.size(); i += 2)
		pairs.push_back(std::make_pair(_v[i], _v[i + 1]));\
	_v.clear();

	if (pairs.size() == 1)
	{
		if (pairs[0].first > pairs[0].second)
			std::swap(pairs[0].first, pairs[0].second);
		_v.push_back(pairs[0].first);
		_v.push_back(pairs[0].second);
		return;
	}
	for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
	{
		if (it->first > it->second)
			std::swap(it->first, it->second);
	}
	std::vector<std::pair<int, int> > new_pairs;

	if (pairs.size() % 2 != 0)
	{
		for (size_t i = 0; i < pairs.size() - 1; i += 2)
			new_pairs.push_back(std::make_pair(pairs[i].second, pairs[i + 1].second));
		new_pairs.push_back(std::make_pair(pairs[pairs.size() - 1].first, pairs[pairs.size() - 1].second));
		pairs.erase(pairs.end() - 1);
	}
	else
	{
		for (size_t i = 0; i < pairs.size(); i += 2)
			new_pairs.push_back(std::make_pair(pairs[i].second, pairs[i + 1].second));
	}

	recursionSortv(new_pairs);

	std::vector<int> pend;
	for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
	{
		pend.push_back(it->first);
	}
	std::vector<int> jacobsthal = jacobsthalSequenceD<std::vector<int> >(pend.size());
	std::vector<int> insertionSequence = insertSequence(jacobsthal, jacobsthal.size());
	for (size_t i = 0; i < pend.size(); i++)
		binaryInsert(_v, pend[insertionSequence[i]]);
}
