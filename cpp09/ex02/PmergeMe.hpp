/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 21:26:43 by ofadhel           #+#    #+#             */
/*   Updated: 2024/08/03 22:52:38 by ofadhel          ###   ########.fr       */
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

class PmergeMe
{
	private:
		std::vector<int> _v; //or list
		std::deque<int> _d;
		//time deaque;
		//time vector;
	public:
		PmergeMe(std::deque<int> d);
		PmergeMe(PmergeMe const &src);
		~PmergeMe();
		PmergeMe &operator=(PmergeMe const &rhs);

		void start();
		int jacobsthal(int n);
		void print();

};

#endif
