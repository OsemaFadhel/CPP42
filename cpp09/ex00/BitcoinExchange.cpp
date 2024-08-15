/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 15:30:10 by ofadhel           #+#    #+#             */
/*   Updated: 2024/08/15 20:19:29 by ofadhel          ###   ########.fr       */
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

void BitcoinExchange::checkfiles(std::string const filename)
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
		_datacsv.insert(std::pair<std::string, double>(date, rate));
	}
	//print map
	/*for (std::map<std::string, double>::iterator it = _datacsv.begin(); it != _datacsv.end(); ++it)
		std::cout << it->first << " => " << std::fixed << std::setprecision(2) << it->second << '\n';
	std::cout << std::endl;*/
	file.close();
}

int *getdate(std::string date)
{
	int *dates = new int[3];
	std::string year = date.substr(0, 4);
	std::string month = date.substr(5, 2);
	std::string day = date.substr(8, 2);
	dates[0] = std::atoi(year.c_str());
	dates[1] = std::atoi(month.c_str());
	dates[2] = std::atoi(day.c_str());
	return dates;
}

int checkDate(std::string date)
{
	if (date.length() != 10)
	{
		std::cout << "Error: bad input => " << date << std::endl;
		return 1;
	}
	if (date[4] != '-' || date[7] != '-')
	{
		std::cout << "Error: bad input => " << date << std::endl;
		return 1;
	}

	int *dates = getdate(date);
	if (dates[0] < 2000 || dates[0] > 2022)
	{
		std::cout << "Error: bad input => " << date << std::endl;
		return 1;
	}
	if (dates[1] < 1 || dates[1] > 12)
	{
		std::cout << "Error: bad input => " << date << std::endl;
		return 1;
	}
	if (dates[2] < 1 || dates[2] > 31)
	{
		std::cout << "Error: bad input => " << date << std::endl;
		return 1;
	}

	delete[] dates;
	return 0;
}

void BitcoinExchange::execute(std::string const &date, double const rate)
{
	//find the closest date in data.csv map and multiply the rate with the exchange rate
	//print the result date => rate
	(void)date;
	(void)rate;


}

void BitcoinExchange::readinput(std::string const &filename)
{
	std::ifstream file(filename.c_str());
	std::string line;
	std::string date;
	std::string value;
	double rate;

	getline(file, line);
	//• Each line in this file must use the following format: "date | value"
	if (line != "date | value")
		throw std::runtime_error("Error: bad format in the first line.");

	while (std::getline(file, line))
	{
		if (line.empty()) //skip empty lines
			continue;
		if (line.find('|') == std::string::npos) //check if | is present in the line
			std::cout << "Error: bad input => " << line << std::endl;
		else
		{
			std::stringstream ss(line);
			std::getline(ss, date, '|');
			std::getline(ss, value);
			//check date format if it is Year-Month-Day, and its valid date. If not, print error message
			//Error: bad input => <date>
			date.erase(0, date.find_first_not_of(" \n\r\t")); //remove leading spaces
			date.erase(date.find_last_not_of(" \n\r\t") + 1); //remove trailing spaces
			if (checkDate(date) == 1)
				continue;

			// Convert value to double
			std::istringstream(value) >> rate;

			//check rate if it is between 0 and 1000
			if (rate < 0)
			{
				std::cout << "Error: not a positive number." << std::endl;
				continue;
			}
			else if (rate > 1000)
			{
				std::cout << "Error: too large a number." << std::endl;
				continue;
			}

			std::cout << date << " => " << std::fixed << std::setprecision(2) << rate << std::endl;
			//execute(date, rate);
		}
	}
}

void BitcoinExchange::exchange(std::string const &filename)
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
