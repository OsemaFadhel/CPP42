/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 21:26:43 by ofadhel           #+#    #+#             */
/*   Updated: 2024/08/11 15:36:21 by ofadhel          ###   ########.fr       */
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
		std::deque<int> _d;
		std::vector<int> _v;
		int _straggler;
	public:
		PmergeMe(std::deque<int> d, std::vector<int> v);
		PmergeMe(PmergeMe const &src);
		~PmergeMe();
		PmergeMe &operator=(PmergeMe const &rhs);

		void start();
		void startVector();
		int jacobsthal(int n);
		void printDeque(std::string const str);
		void recursionSort(std::deque<std::pair<int, int> > &pairs);
		void recursionSortv(std::vector<std::pair<int, int> > &pairs);

		template <typename T>
		T jacobsthalSequenceD(int n);

		template <typename T>
		T insertSequence(T jacobsthal, int n);

		template <typename T>
		void binaryInsert(T &main, int n);
};

#endif
