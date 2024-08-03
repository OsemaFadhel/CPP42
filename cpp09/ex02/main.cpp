/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 21:26:23 by ofadhel           #+#    #+#             */
/*   Updated: 2024/08/03 22:48:27 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void findDuplicate(std::deque<int> *deq, int n) //check if there is any duplicate numbers
{
	for (std::deque<int>::iterator it = deq->begin(); it != deq->end(); it++)
	{
		if (*it == n)
			throw std::invalid_argument("No duplicate numbers allowed");
	}
}

void checkArg(char **av, std::deque<int> *deq)
{
	for (int i = 0; av[i]; i++)
	{
		std::string arg(av[i]);
		for (size_t i = 0; i < arg.length(); i++)
		{
			if (!std::isdigit(arg[i]))
				throw std::invalid_argument("All elements must be positive integers.");
		}
		int num = std::atoi(arg.c_str());
		if (num <= 0)
			throw std::invalid_argument("All elements must be positive integers, and not greater then 2147483647. OVERFLOW");
		if (i > 0)
			findDuplicate(deq, num);
		deq->push_back(num);
	}
}

int main(int ac, char **av)
{
	if (ac < 3)
	{
		std::cerr << "Usage: ./Pmergeme [numbers]" << std::endl;
		return 1;
	}
	try
	{
		std::deque<int> deq;
		::checkArg(++av, &deq); //check if the argument are all positive numbers
		PmergeMe p(deq);
		//p.start();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}
