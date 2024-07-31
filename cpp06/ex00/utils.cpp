/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:41:03 by ofadhel           #+#    #+#             */
/*   Updated: 2024/07/31 15:41:21 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

int findtype(std::string _input)
{
	int _type = -1;
	if (_input.length() == 1 && !std::isdigit(_input[0])) {
		_type = 0;
		return _type;
	}
	char *end;
	long value = std::strtol(_input.c_str(), &end, 10);
	if (*end == '\0' && value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max()) {
		_type = 1;
		return _type;
	}
	std::strtof(_input.c_str(), &end);
	if (*end == 'f' && *(end + 1) == '\0') {
		_type = 2;
		return _type;
	}
	std::strtod(_input.c_str(), &end);
	if (*end == '\0') {
		_type = 3;
		return _type;
	}

	return _type;
}

void printChar(char c)
{
	if (std::isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

void printInt(int i)
{
	std::cout << "int: " << i << std::endl;
}

void printFloat(float f) {
	if (isSpecialFloat(f))
		std::cout << "float: " << f << "f" << std::endl;
	else
		std::cout << "float: " <<  std::fixed << std::setprecision(floor(f) == f ? 1 : 6) << f << "f" << std::endl;
}

void printDouble(double d) {
	if (isSpecialDouble(d))
	std::cout << "double: " << d << std::endl;
	else
		std::cout << "double: " << std::fixed << std::setprecision(floor(d) == d ? 1 : 6) << d << std::endl;
}

bool isSpecialFloat(float f) {
	return f == std::numeric_limits<float>::infinity() ||
			f == -std::numeric_limits<float>::infinity() ||
			f != f;
}

bool isSpecialDouble(double d) {
	return d == std::numeric_limits<double>::infinity() ||
			d == -std::numeric_limits<double>::infinity() ||
			d != d;
}
