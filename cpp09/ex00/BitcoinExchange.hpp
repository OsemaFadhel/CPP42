/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 15:30:07 by ofadhel           #+#    #+#             */
/*   Updated: 2024/08/15 19:44:53 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <cmath>
#include <iomanip>

class BitcoinExchange
{
	private:
		std::multimap<std::string, double> _datacsv;
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange &operator=(BitcoinExchange const &obj);
		BitcoinExchange(BitcoinExchange const &obj);
		void exchange(std::string const &filename);
		void checkfiles(std::string const filename);
		void readcsv();
		void readinput(std::string const &filename);
		void execute(std::string const &date, double const rate);
};

#endif
