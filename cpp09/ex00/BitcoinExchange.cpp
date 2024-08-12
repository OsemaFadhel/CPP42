/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 15:30:10 by ofadhel           #+#    #+#             */
/*   Updated: 2024/08/12 18:07:36 by ofadhel          ###   ########.fr       */
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
	(void)filename;
	std::ifstream datafile("data.csv");
	if (!datafile)
		throw std::runtime_error("Error: data.csv file is missing.");
	if (datafile.peek() == std::ifstream::traits_type::eof())
		throw std::runtime_error("Error: data file is empty.");
	/*std::ifstream file(filename);
	if (!file)
		throw std::runtime_error("Error: could not open file.");
	if (file.peek() == std::ifstream::traits_type::eof())
		throw std::runtime_error("Error: file is empty.");
	file.close();*/
	datafile.close();

}

void BitcoinExchange::readcsv()
{
	std::ifstream file("data.csv");
	std::string line;
	std::string date;
	std::string exchangeRate;
	double rate;
	getline(file, line);

	while (std::getline(file, line)) {
		std::stringstream ss(line);
		std::getline(ss, date, ',');
		std::getline(ss, exchangeRate);
		// Convert exchangeRate to double
		std::istringstream(exchangeRate) >> rate;
		// Store the rate in the map
		_datacsv[date] = rate;
	}
	//print map
	/*for (std::map<std::string, double>::iterator it = _datacsv.begin(); it != _datacsv.end(); ++it)
		std::cout << it->first << " => " << std::fixed << std::setprecision(2) << it->second << '\n';
	std::cout << std::endl;*/
	file.close();
}

void BitcoinExchange::readinput(std::string filename)
{
	(void)filename;
	std::ifstream file("input.txt");
	std::string line;
	std::string date;
	std::string value;
	double rate;

	getline(file, line);
	if (line != "date | value")
		throw std::runtime_error("Error: invalid file format.");
	while (std::getline(file, line))
	{
		if (line.empty())
			continue;
		if (line.find('|') == std::string::npos)
			std::cout << "Error: bad input => " << line << std::endl;
		else
		{
			std::stringstream ss(line);
			std::getline(ss, date, '|');
			std::getline(ss, value);
			// Convert value to double
			std::istringstream(value) >> rate;
			//add to multimap
			_values.insert(std::make_pair(date, rate));
		}
	}
	//print map
	for (std::map<std::string, double>::iterator it = _values.begin(); it != _values.end(); ++it)
		std::cout << it->first << " => " << std::fixed << std::setprecision(2) << it->second << '\n';
	std::cout << std::endl;
}

void BitcoinExchange::exchange(std::string filename)
{
	try
	{
		checkfiles(filename);
		//std::ifstream file(filename);
		readcsv();
		readinput(filename);
		//file.close();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return;
	}
}
