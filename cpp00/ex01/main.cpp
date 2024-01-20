/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:58:52 by ofadhel           #+#    #+#             */
/*   Updated: 2024/01/21 00:08:28 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebookClass.hpp"

void	printHelpPage()
{
	std::cout << "--------------------------------" << std::endl;
	std::cout << "-   Welcome to the phonebook!  -" << std::endl;
	std::cout << "------------HELP PAGE-----------" << std::endl;
	std::cout << "-    ADD: Add a new contact    -" << std::endl;
	std::cout << "- SEARCH: Search for a contact -" << std::endl;
	std::cout << "-    EXIT: Exit the program    -" << std::endl;
	std::cout << "--------------------------------" << std::endl;
}

void	PhoneBook::search()
{
	printContacts();

}

int main()
{
	std::string input;
	PhoneBook phonebook;

	printHelpPage();
	while (1)
	{
		std::cout << "\033[1;32mENTER A COMMAND:> \033[0m";
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << "Exiting..." << std::endl;
			return (0);
		}
		if (input == "EXIT")
		{
			std::cout << "Exiting..." << std::endl;
			return (0);
		}
		else if (input == "ADD")
			phonebook.add();
		else if (input == "SEARCH")
			phonebook.search();
		else
			std::cout << "Invalid command" << std::endl;
	}
	return (0);
}
