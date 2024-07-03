/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:39:07 by ofadhel           #+#    #+#             */
/*   Updated: 2024/07/01 10:45:53 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	_input = "";
}

ScalarConverter::ScalarConverter(std::string input) : _input(input)
{
	findtype();
}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
	*this = src;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &src)
{
	if (this != &src)
		_input = src._input;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
}

void ScalarConverter::setInput(std::string input)
{
	_input = input;
}

std::string ScalarConverter::getInput() const
{
	return _input;
}

void ScalarConverter::findtype()
{
	if (_input.length() == 1 && !std::isdigit(_input[0]))
		_type = 0;
	else if (_input )
}

void ScalarConverter::convert()
{
	printChar();
	printInt();
	printFloat();
	printDouble();
}

void ScalarConverter::printChar()
{
	std::cout << "char: ";
	try
	{
		if (_input.length() > 1 && !std::isdigit(_input[0])
		{
			std::cout << "'" << _input << "'";
			return;
		}
	}
	catch (std::exception &e)
	{
		std::cout << "impossible" << std::endl;
		return;
	}
}

void ScalarConverter::printInt()
{
	std::cout << "int: ";
	try
	{
		int i = std::stoi(_input);
		if (i > std::numeric_limits<int>::max() || i < std::numeric_limits<int>::min())
			std::cout << "impossible";
		else
			std::cout << i;
	}
	catch (std::exception &e)
	{
		std::cout << "impossible";
	}
	std::endl;
}

void ScalarConverter::printFloat()
{
	std::cout << "float: ";
	try
	{
		float f = std::stof(_input);
	}
	...
	std::endl;
}

void ScalarConverter::printDouble()
{
	std::cout << "double: ";
	try
	{
		double d = std::stod(_input);
	}
	...
	std::endl;
}
