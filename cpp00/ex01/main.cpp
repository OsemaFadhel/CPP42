/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:58:52 by ofadhel           #+#    #+#             */
/*   Updated: 2024/01/16 20:59:19 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook_class.hpp"
#include "contact_class.hpp"

int main()
{
	std::string input;
	PhoneBook phonebook;

	while (1)
	{
		std::cout << "Enter a command: ";
		std::getline(std::cin, input);
		if (input == "EXIT")
			break;
		else if (input == "ADD")
			phonebook.add();
		else if (input == "SEARCH")
			phonebook.search();
		else
			std::cout << "Invalid command" << std::endl;
	}
	return (0);
}
