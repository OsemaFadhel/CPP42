/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 22:42:59 by ofadhel           #+#    #+#             */
/*   Updated: 2024/08/07 12:32:00 by ofadhel          ###   ########.fr       */
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
	jacobsthal.push_back(1);
	jacobsthal.push_back(1);
	for (int i = 2; i < n; i++)
		jacobsthal.push_back(jacobsthal[i - 1] + 2 * jacobsthal[i - 2]);
	return jacobsthal;
}

template <typename T>
T PmergeMe::insertSequence(T jacobsthal, int size)
{
	T insertionSequence;
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
	if (pairs.size() == 1)
	{
		if (pairs[0].first > pairs[0].second)
			std::swap(pairs[0].first, pairs[0].second);
		_d.push_back(pairs[0].first);
		_d.push_back(pairs[0].second);
		return;
	}
	for (std::deque<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
	{
		if (it->first > it->second)
			std::swap(it->first, it->second);
	}
	std::deque<std::pair<int, int> > new_pairs;
	for (size_t i = 0; i < pairs.size(); i += 2)
		new_pairs.push_back(std::make_pair(pairs[i].second, pairs[i + 1].second));
	//print the pairs
	recursionSort(new_pairs);
	std::deque<int> pend;
	for (std::deque<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
		pend.push_back(it->first);
	for (std::deque<int>::iterator it = pend.begin(); it != pend.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::deque<int> jacobsthal = jacobsthalSequenceD<std::deque<int> >(pend.size());
	std::deque<int> insertionSequence = insertSequence(jacobsthal, pend.size());
	for (size_t i = 0; i < pend.size(); i++)
		binaryInsert(_d, pend[insertionSequence[i] - 1]);

}

void PmergeMe::start()
{
	//0. start timer
	//std::clock_t start_d = std::clock();
	//1. first check if the deque is even or odd.  If odd, remove the last element and call it straggler
	if (_d.size() % 2 != 0)
	{
		_straggler = _d.back();
		_d.pop_back();
	}
	std::cout << std::endl;

	//2. Now we can start creating pairs
	std::deque<std::pair<int, int> > pairs;


	recursionSort(pairs);



/*
	//3. Sorting the pairs, [a, b] where a < b
 	for (std::deque<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
	{
		if (it->first > it->second)
			std::swap(it->first, it->second);
	}*/

	//here it should start the recursive sort or maybe the pair step before put it in the recursion



/*
	//5. Create a new sequence ‘pend’, by pulling out the [highest] value of each pair and inserting it into ‘pend’.
	std::deque<int> pend;
	for (std::deque<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
	{
		_d.push_back(it->second);
		pend.push_back(it->first);
	}
	if (_straggler != -1)
		pend.push_back(_straggler);

	//6. Based on the length of ‘pend’, build the optimal insertion sequence using relevant Jacobsthal numbers.
	std::deque<int> jacobsthal = jacobsthalSequenceD<std::deque<int> >(pend.size());
	std::deque<int> insertionSequence = insertSequence(jacobsthal, pend.size());

	//7. Loop through the elements in ‘pend’, and using the insertion sequence built in the previous step, use binary search to insert each ‘pend’ element into ‘_d’
	for (size_t i = 0; i < pend.size(); i++)
		binaryInsert(_d, pend[insertionSequence[i] - 1]);

	//end timer
	std::clock_t end_d = std::clock();
	double process_time_deque = double(end_d - start_d) / CLOCKS_PER_SEC;
*/
	printDeque("After: ");
	//startVector(); //now do the same with vector
	//std::cout << "Time to process a range of " << _d.size() << " elements with std::deque: " << std::fixed << process_time_deque << "us" << std::endl;

}


// Vector to change

void PmergeMe::startVector()
{
	std::clock_t start_v = std::clock();
	if (_v.size() % 2 != 0)
	{
		_straggler = _v.back();
		_v.pop_back();
	}

	std::vector<std::pair<int, int> > pairs;
	for (size_t i = 0; i < _v.size(); i += 2)
		pairs.push_back(std::make_pair(_v[i], _v[i + 1]));
	_v.clear();

 	for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
	{
		if (it->first > it->second)
			std::swap(it->first, it->second);
	}

	std::vector<int> pend;
	for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
	{
		_v.push_back(it->second);
		pend.push_back(it->first);
	}
	if (_straggler != -1)
		pend.push_back(_straggler);

	std::vector<int> jacobsthal = jacobsthalSequenceD<std::vector<int> >(pend.size());
	std::vector<int> insertionSequence = insertSequence(jacobsthal, pend.size());

	for (size_t i = 0; i < pend.size(); i++)
		binaryInsert(_v, pend[insertionSequence[i] - 1]);

	std::clock_t end_v = std::clock();
	double process_time_vector = double(end_v - start_v) / CLOCKS_PER_SEC;

	std::cout << "Time to process a range of " << _v.size() << " elements with std::vector: " << std::fixed << process_time_vector << "us" << std::endl;
}

/* TEst with prints
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
	if (_straggler != -1)
		pend.push_back(_straggler);
	//print the 2 sequences
	for (std::deque<int>::iterator it = main.begin(); it != main.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	for (std::deque<int>::iterator it = pend.begin(); it != pend.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl << std::endl;

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

	//8. Finally, if there was a straggler, insert it into ‘main’ using binary search. THE END!!!
	if (_straggler != -1)
	{
		std::cout << "Inserting straggler" << std::endl;
		binaryInsert(main, _straggler);
	}
	//print the main sequence
	for (std::deque<int>::iterator it = main.begin(); it != main.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl << std::endl;
}
*/

