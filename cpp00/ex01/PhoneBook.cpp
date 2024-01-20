/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:59:25 by ofadhel           #+#    #+#             */
/*   Updated: 2024/01/20 23:48:51 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebookClass.hpp"

PhoneBook::PhoneBook() : index(0)
{
	return ;
}

PhoneBook::~PhoneBook()
{
	return ;
}

void	PhoneBook::add()
{
	std::string input;

	if (this->index == 9)
		this->index = 0;
	std::cout << "Enter first name: ";
	std::getline(std::cin, input);
	this->contacts[this->index].setFirstName(input);
	while (this->contacts[this->index].getFirstName().empty())
	{
		std::cout << "CAN'T BE EMPTY" << std::endl;
		std::cout << "Enter first name: ";
		std::getline(std::cin, input);
		this->contacts[this->index].setFirstName(input);
	}
	std::cout << "Enter last name: ";
	std::getline(std::cin, input);
	this->contacts[this->index].setLastName(input);
	while (this->contacts[this->index].getLastName().empty())
	{
		std::cout << "CAN'T BE EMPTY" << std::endl;
		std::cout << "Enter last name: ";
		std::getline(std::cin, input);
		this->contacts[this->index].setLastName(input);
	}
	std::cout << "Enter nickname: ";
	std::getline(std::cin, input);
	this->contacts[this->index].setNickname(input);
	while (this->contacts[this->index].getNickname().empty())
	{
		std::cout << "CAN'T BE EMPTY" << std::endl;
		std::cout << "Enter nickname: ";
		std::getline(std::cin, input);
		this->contacts[this->index].setNickname(input);
	}
	std::cout << "Enter phone number: ";
	std::getline(std::cin, input);
	this->contacts[this->index].setPhoneNumber(input);
	while (this->contacts[this->index].getPhoneNumber().empty())
	{
		std::cout << "Invalid input" << std::endl;
		std::cout << "Enter phone number: ";
		std::getline(std::cin, input);
		this->contacts[this->index].setPhoneNumber(input);
	}
	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, input);
	this->contacts[this->index].setDarkestSecret(input);
	while (this->contacts[this->index].getDarkestSecret().empty())
	{
		std::cout << "CAN'T BE EMPTY" << std::endl;
		std::cout << "Enter darkest secret: ";
		std::getline(std::cin, input);
		this->contacts[this->index].setDarkestSecret(input);
	}
	this->index++;
}

std::string getTrunString(std::string str)
{
	std::string newStr;

	if (str.length() > 10)
	{
		newStr = str.substr(0, 9);
		newStr += ".";
		return (newStr);
	}
	return (str);
}

void	PhoneBook::printContacts()
{
	int i = 0;

	std::cout << "------------------------------------------" << std::endl;
	std::cout << "   Index  |First name| Last name| Nickname" << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	while (i < this->index)
	{
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << getTrunString(this->contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << getTrunString(this->contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << getTrunString(this->contacts[i].getNickname()) << std::endl;
		i++;
	}
	std::cout << "------------------------------------------" << std::endl;
}
