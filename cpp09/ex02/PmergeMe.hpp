/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 21:26:43 by ofadhel           #+#    #+#             */
/*   Updated: 2024/08/04 21:06:03 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <vector>
# include <deque>
# include <cstdlib>
# include <cctype>
# include <cmath>
# include <algorithm>
# include <limits>
# include <stdexcept>
# include <exception>
# include <ctime>
# include <utility>

class PmergeMe
{
	private:
		std::vector<int> _v; //or list
		std::deque<int> _d;
		int _straggler;
		//time deaque;
		//time vector;
	public:
		PmergeMe(std::deque<int> d);
		PmergeMe(PmergeMe const &src);
		~PmergeMe();
		PmergeMe &operator=(PmergeMe const &rhs);

		void start();
		int jacobsthal(int n);
		void print(std::string const str);
		std::deque<std::pair<int, int> > createPairs();
		std::deque<int> jacobsthalSequence(int n);
		std::deque<int> insertSequence(std::deque<int> jacobsthal, int n);
		void binaryInsert(std::deque<int> &main, int value);
};

#endif
