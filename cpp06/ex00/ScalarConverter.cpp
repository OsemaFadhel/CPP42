/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:39:07 by ofadhel           #+#    #+#             */
/*   Updated: 2024/04/26 16:39:07 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	_input = "";
}

ScalarConverter::ScalarConverter(std::string input) : _input(input)
{
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
		int i = std::stoi(_input);
	}
	...
}

void ScalarConverter::printInt()
{
	std::cout << "int: ";
	try
	{
		int i = std::stoi(_input);
	}
	...
}

void ScalarConverter::printFloat()
{
	std::cout << "float: ";
	try
	{
		float f = std::stof(_input);
	}
	...
}

void ScalarConverter::printDouble()
{
	std::cout << "double: ";
	try
	{
		double d = std::stod(_input);
	}
	...
}
