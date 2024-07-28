/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 15:30:07 by ofadhel           #+#    #+#             */
/*   Updated: 2024/07/28 16:04:28 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class BitcoinExchange
{
	private:
		std::map<std::string, double> _values;
		std::map<std::string, double> _datacsv;
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange &operator=(BitcoinExchange const &obj);
		BitcoinExchange(BitcoinExchange const &obj);
		void exchange(std::string filename);
		void checkfiles(std::string filename);
		void readfiles(std::ifstream file, std::ifstream datafile);
};

#endif
