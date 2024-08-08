/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:47:41 by ofadhel           #+#    #+#             */
/*   Updated: 2024/08/08 17:14:57 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void printInt(int &x)
{
	std::cout << x << std::endl;
}

void printDouble(double &x)
{
	std::cout << x << std::endl;
}

void printString(std::string &x)
{
	std::cout << x << std::endl;
}

int main()
{
	int intArray[] = {1, 2, 3, 4, 5};
	double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	std::string stringArray[] = {"Hello", "World", "!"};

	std::cout << "Integer Array:" << std::endl;
	iter(intArray, 5, printInt);

	std::cout << "Double Array:" << std::endl;
	iter(doubleArray, 5, printDouble);

	std::cout << "String Array:" << std::endl;
	iter(stringArray, 3, printString);

	return 0;
}
