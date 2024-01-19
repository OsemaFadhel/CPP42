/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:58:52 by ofadhel           #+#    #+#             */
/*   Updated: 2024/01/19 17:50:18 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook_class.hpp"
//#include "contact_class.hpp"

void	PhoneBook::add()
{
	if (this->index == 9)
		this->index = 0;
	std::cout << "Enter first name: ";
	std::getline(std::cin, this->contacts[this->index].first_name);
	while (this->contacts[this->index].first_name.empty())
	{
		std::cout << "Invalid input" << std::endl;
		std::cout << "Enter first name: ";
		std::getline(std::cin, this->contacts[this->index].first_name);
	}
	std::cout << "Enter last name: ";
	std::getline(std::cin, this->contacts[this->index].last_name);
	while (this->contacts[this->index].last_name.empty())
	{
		std::cout << "Invalid input" << std::endl;
		std::cout << "Enter last name: ";
	std::getline(std::cin, this->contacts[this->index].last_name);
	}
	std::cout << "Enter nickname: ";
	std::getline(std::cin, this->contacts[this->index].nickname);
	while (this->contacts[this->index].nickname.empty())
	{
		std::cout << "Invalid input" << std::endl;
		std::cout << "Enter nickname: ";
		std::getline(std::cin, this->contacts[this->index].nickname);
	}
	std::cout << "Enter phone number: ";
	std::getline(std::cin, this->contacts[this->index].phone_number);
	while (this->contacts[this->index].phone_number.empty())
	{
		std::cout << "Invalid input" << std::endl;
		std::cout << "Enter phone number: ";
		std::getline(std::cin, this->contacts[this->index].phone_number);
	}
	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, this->contacts[this->index].darkest_secret);
	while (this->contacts[this->index].darkest_secret.empty())
	{
		std::cout << "Invalid input" << std::endl;
		std::cout << "Enter darkest secret: ";
		std::getline(std::cin, this->contacts[this->index].darkest_secret);
	}
	this->index++;
}

void	print_help_page()
{
	std::cout << "--------------------------------" << std::endl;
	std::cout << "-   Welcome to the phonebook!  -" << std::endl;
	std::cout << "------------HELP PAGE-----------" << std::endl;
	std::cout << "-    ADD: Add a new contact    -" << std::endl;
	std::cout << "- SEARCH: Search for a contact -" << std::endl;
	std::cout << "-    EXIT: Exit the program    -" << std::endl;
	std::cout << "--------------------------------" << std::endl;
}

void	PhoneBook::print_contacts()
{
	std::cout << "--------------------------------" << std::endl;
	std::cout << "Index | First name | Last name | Nickname" << std::endl;
	while (!this->contacts[this->index].first_name.empty())
	{
		std::cout << std::setw(10) << this->index << "|";
		std::cout << std::setw(10) << this->contacts[this->index].first_name << "|";
		std::cout << std::setw(10) << this->contacts[this->index].last_name << "|";
		std::cout << std::setw(10) << this->contacts[this->index].nickname << std::endl;
		this->index++;
	}
}

void	PhoneBook::search()
{
	print_contacts();

}

int main()
{
	std::string input;
	PhoneBook phonebook;

	phonebook.index = 0;
	while (1)
	{
		print_help_page();
		std::cout << "Enter a command: ";
		std::getline(std::cin, input);
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
