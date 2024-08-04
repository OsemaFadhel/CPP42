/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 22:42:59 by ofadhel           #+#    #+#             */
/*   Updated: 2024/08/04 21:21:02 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(std::deque<int> d) : _d(d)
{
	_straggler = -1; //used like a flag if the sequence is odd
	print("Before: ");
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

// Compare pairs by the value of it’s largest pair.
struct ComparePairs
{
	bool operator()(std::pair<int, int> const &a, std::pair<int, int> const &b)
	{
		return std::max(a.first, a.second) < std::max(b.first, b.second);
	}
};

void PmergeMe::start()
{
	//1. first check if the deque is even or odd.  If odd, remove the last element and call it straggler
	std::cout << "Checking if even or odd" << std::endl;
	if (_d.size() % 2 != 0)
	{
		_straggler = _d.back();
		_d.pop_back();
	}
	std::cout << std::endl;

	//2. Now we can start creating pairs
	std::cout << "Creating pairs" << std::endl;
	std::deque<std::pair<int, int> > pairs;
	for (size_t i = 0; i < _d.size(); i += 2)
		pairs.push_back(std::make_pair(_d[i], _d[i + 1]));
	_d.clear();
	//print the pairs
	for (std::deque<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
		std::cout << "[" << it->first << ", " << it->second << "] ";
	std::cout << std::endl << std::endl;

	//3. Sorting the pairs, [a, b] where a < b
	std::cout << "Sorting pairs" << std::endl;
 	for (std::deque<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
	{
		if (it->first > it->second)
			std::swap(it->first, it->second);
	}
	//print the pairs
	for (std::deque<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
		std::cout << "[" << it->first << ", " << it->second << "] ";
	std::cout << std::endl << std::endl;

	//4. Sort the sequence recursively by the value of it’s largest pair.
	std::cout << "Sorting sequence" << std::endl;
	std::sort(pairs.begin(), pairs.end(), ComparePairs()); //maybe rewrite sort function
	//print the pairs
	for (std::deque<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
		std::cout << "[" << it->first << ", " << it->second << "] ";
	std::cout << std::endl << std::endl;

	//5. Create a new sequence ‘pend’, by pulling out the [highest] value of each pair and inserting it into ‘pend’.
	std::cout << "Creating new sequence" << std::endl;
	std::deque<int> main, pend;
	for (std::deque<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
	{
		main.push_back(it->second);
		pend.push_back(it->first);
	}
	pend.push_back(_straggler);
	//print the 2 sequences
	for (std::deque<int>::iterator it = main.begin(); it != main.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	for (std::deque<int>::iterator it = pend.begin(); it != pend.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl << std::endl;

	/************************************************************************************
	At this point, we could take any of the bs and use binary-search-insertion
	to insert that b into the main-chain (which starts of as just the as).
	When inserting, we only need to consider the values "left" of the b in question
	(for example, when inserting b4 we only need to consider the chain up to and including a3).
	We could insert the bs in order (b1, b2 ...), but the "key insight"
	from above suggest otherwise. Different bs have different worst-case costs
	to insert into the main-chain (worst case cost for binary-search-insertion
	is floor(log2(N) where N is the length of the relevant part of the main-chain).
	We can minimize the cost by following an order based on the
	Jacobsthal Numbers: 1 3 2 5 4 11 10 9 8 7 6 21 20 19 18...
	(ignoring values which are greater than the bs we have).
	And so, we insert the bs, one at a time, into the main-chain following
	the above progression, eventually resulting in a sorted list.
	************************************************************************************/

	//6. Based on the length of ‘pend’, build the optimal insertion sequence using relevant Jacobsthal numbers.
	std::cout << "Building Jacobsthal sequence" << std::endl;
	std::deque<int> jacobsthal = jacobsthalSequence(pend.size());
	std::cout << "Building insertion sequence: " << std::endl;
	std::deque<int> insertionSequence = insertSequence(jacobsthal, pend.size());




	//check sequence before big work
	std::cout << "Insertion sequence: ";
	for (std::deque<int>::iterator it = insertionSequence.begin(); it != insertionSequence.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "main sequence: ";
	for (std::deque<int>::iterator it = main.begin(); it != main.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "pend sequence: ";
	for (std::deque<int>::iterator it = pend.begin(); it != pend.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl << std::endl;


	//7. Loop through the elements in ‘pend’, and using the insertion sequence built in the previous step, use binary search to insert each ‘pend’ element into ‘main’
	std::cout << "Inserting elements into main" << std::endl;
	for (size_t i = 0; i < pend.size(); i++)
		binaryInsert(main, pend[insertionSequence[i] - 1]);
	//print the main sequence
	for (std::deque<int>::iterator it = main.begin(); it != main.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl << std::endl;

	/*//8. Finally, if there was a straggler, insert it into ‘main’ using binary search. THE END!!!
	if (_straggler != -1)
	{
		std::cout << "Inserting straggler" << std::endl;
		binaryInsert(main, _straggler);
	}*/
	//print the main sequence
	for (std::deque<int>::iterator it = main.begin(); it != main.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl << std::endl;
}

void PmergeMe::print(std::string const str)
{
	std::cout << str;
	for (std::deque<int>::iterator it = _d.begin(); it != _d.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

std::deque<int> PmergeMe::jacobsthalSequence(int n)
{
	std::deque<int> jacobsthal;
	jacobsthal.push_back(1);
	jacobsthal.push_back(1);
	for (int i = 2; i < n; i++)
		jacobsthal.push_back(jacobsthal[i - 1] + 2 * jacobsthal[i - 2]);
	return jacobsthal;
}

std::deque<int> PmergeMe::insertSequence(std::deque<int> jacobsthal, int size)
{
	std::deque<int> insertionSequence;
	/*for (int i = 0; i < n; i++)
	{
		int j = 0;
		while (jacobsthal[j] < i)
			j++;
		insertionSequence.push_back(jacobsthal[j]);
	}
	return insertionSequence;*/
	/*or gotta study this*/
	size_t jacobsthal_index = 0;
	for (int i = 0; i < size; ++i)
	{
		if (jacobsthal_index < jacobsthal.size() && jacobsthal[jacobsthal_index] == i + 1)
		{
			insertionSequence.push_back(jacobsthal[jacobsthal_index]);
			++jacobsthal_index;
		}
		else
			insertionSequence.push_back(i + 1);
	}
	return insertionSequence;
}

void PmergeMe::binaryInsert(std::deque<int> &main, int value)
{
	std::deque<int>::iterator it = std::lower_bound(main.begin(), main.end(), value);
	main.insert(it, value);
}

