/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:56:17 by ofadhel           #+#    #+#             */
/*   Updated: 2024/07/21 22:09:08 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main() {
	try {
		Array<int> arr1;
		std::cout << "Default constructor, size: " << arr1.size() << std::endl;

		Array<int> arr2(5);
		std::cout << "Constructor with size 5, size: " << arr2.size() << std::endl;

		Array<int> arr3(arr2);
		std::cout << "Copy constructor, size: " << arr3.size() << std::endl;

		Array<int> arr4;
		arr4 = arr3;
		std::cout << "Assignment operator, size: " << arr4.size() << std::endl;

		for (unsigned int i = 0; i < arr2.size(); ++i) {
			arr2[i] = i * 10;
			std::cout << "arr2[" << i << "]: " << arr2[i] << std::endl;
		}
		try
		{
			std::cout << arr2[10] << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
