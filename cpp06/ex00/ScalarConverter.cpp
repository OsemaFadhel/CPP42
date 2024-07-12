/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:39:07 by ofadhel           #+#    #+#             */
/*   Updated: 2024/07/12 12:53:31 by ofadhel          ###   ########.fr       */
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

void ScalarConverter::findtype()
{
	if (_input.length() == 1 && !std::isdigit(_input[0])) {
		_type = 0;
		return;
	}

	char *end;
	long value = std::strtol(_input.c_str(), &end, 10);
	if (*end == '\0' && value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max()) {
		_type = 1;
		return;
	}

	std::strtof(_input.c_str(), &end);
	if (*end == 'f' && *(end + 1) == '\0') {
		_type = 2;
		return;
	}

	std::strtod(_input.c_str(), &end);
	if (*end == '\0') {
		_type = 3;
		return;
	}

	_type = -1;
}

void ScalarConverter::convert()
{
	findtype();
	switch (_type) {
		case 0:
		{
			char c = _input[0];
			printChar(c);
			printInt(static_cast<int>(c));
			printFloat(static_cast<float>(c));
			printDouble(static_cast<double>(c));
			break;
		}
		case 1:
		{
			int i = std::atoi(_input.c_str());
			printChar(static_cast<char>(i));
			printInt(i);
			printFloat(static_cast<float>(i));
			printDouble(static_cast<double>(i));
			break;
		}
		case 2:
		{
			float f = std::strtof(_input.c_str(), NULL);
			if (isSpecialFloat(f))
			{
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
				printFloat(f);
				printDouble(static_cast<double>(f));
			}
			else
			{
				printChar(static_cast<char>(f));
				printInt(static_cast<int>(f));
				printFloat(f);
				printDouble(static_cast<double>(f));
			}
			break;
		}
		case 3:
		{
			double d = std::strtod(_input.c_str(), NULL);
			if (isSpecialDouble(d))
			{
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
				printFloat(static_cast<float>(d));
				printDouble(d);
			}
			else
			{
				printChar(static_cast<char>(d));
				printInt(static_cast<int>(d));
				printFloat(static_cast<float>(d));
				printDouble(d);
			}
			break;
		}
		default:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			break;
	}
}

void ScalarConverter::printChar(char c)
{
	if (std::isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

void ScalarConverter::printInt(int i)
{
	std::cout << "int: " << i << std::endl;
}

void ScalarConverter::printFloat(float f) {
	if (isSpecialFloat(f))
		std::cout << "float: " << f << "f" << std::endl;
	else
		std::cout << "float: " << f << "f" << std::endl;
}

void ScalarConverter::printDouble(double d) {
	if (isSpecialDouble(d))
	std::cout << "double: " << d << std::endl;
	else
		std::cout << "double: " << d << std::endl;
}

bool ScalarConverter::isSpecialFloat(float f) {
	return f == std::numeric_limits<float>::infinity() ||
			f == -std::numeric_limits<float>::infinity() ||
			f != f;
}

bool ScalarConverter::isSpecialDouble(double d) {
	return d == std::numeric_limits<double>::infinity() ||
			d == -std::numeric_limits<double>::infinity() ||
			d != d;
}
