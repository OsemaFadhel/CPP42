/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 22:42:59 by ofadhel           #+#    #+#             */
/*   Updated: 2024/08/03 22:51:34 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(std::deque<int> d) : _d(d)
{
	std::cout << "Before:  " << std::endl;
	for (std::deque<int>::iterator it = _d.begin(); it != _d.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
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

int PmergeMe::jacobsthal(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}


void PmergeMe::print()
{
	std::cout << "After:  " << std::endl;
	for (std::vector<int>::iterator it = _v.begin(); it != _v.end(); it++)
		std::cout << *it << " ";
}
