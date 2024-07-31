/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:39:07 by ofadhel           #+#    #+#             */
/*   Updated: 2024/07/31 15:41:47 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
	*this = src;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &src)
{
	(void)src;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
}


void ScalarConverter::convert(std::string _input)
{
	int _type = findtype(_input);

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
			if (i < 0 || i > 127)
				std::cout << "char: impossible" << std::endl;
			else
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
				if (f < 0 || f > 127)
					std::cout << "char: impossible" << std::endl;
				else
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
				if (d < 0 || d > 127)
					std::cout << "char: impossible" << std::endl;
				else
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
