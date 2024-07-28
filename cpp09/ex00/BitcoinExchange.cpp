/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 15:30:10 by ofadhel           #+#    #+#             */
/*   Updated: 2024/07/28 16:04:40 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &obj)
{
	*this = obj;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &obj)
{
	(void)obj;
	return *this;
}

void BitcoinExchange::checkfiles(std::string filename)
{
	std::ifstream datafile("data.csv");
	if (!datafile)
		throw std::runtime_error("Error: data.csv file is missing.");
	if (datafile.peek() == std::ifstream::traits_type::eof())
		throw std::runtime_error("Error: data file is empty.");
	std::ifstream file(filename);
	if (!file)
		throw std::runtime_error("Error: could not open file.");
	if (file.peek() == std::ifstream::traits_type::eof())
		throw std::runtime_error("Error: file is empty.");
	datafile.close();
	file.close();
}

void BitcoinExchange::readfiles(std::ifstream file, std::ifstream datafile)
{

}

void BitcoinExchange::exchange(std::string filename)
{
	try
	{
		checkfiles(filename);
		std::ifstream file(filename);
		std::ifstream datafile("data.csv");
		readfiles(file, datafile);
		file.close();
		datafile.close();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return;
	}
}
