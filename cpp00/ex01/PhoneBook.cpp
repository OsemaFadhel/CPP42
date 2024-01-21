/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:59:25 by ofadhel           #+#    #+#             */
/*   Updated: 2024/01/21 17:11:05 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebookClass.hpp"

PhoneBook::PhoneBook() : index(0), contactCount(-1)
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

	if (this->index == 8)
		this->index = 0;
	std::cout << "\033[1;36mEnter first name: \033[0m";
	clearerr(stdin);
	std::cin.clear();
	std::getline(std::cin, input);
	this->contacts[this->index].setFirstName(input);
	while (this->contacts[this->index].getFirstName().empty())
	{
		std::cout << "CAN'T BE EMPTY" << std::endl;
		std::cout << "\033[1;36mEnter first name: \033[0m";
		clearerr(stdin);
		std::cin.clear();
		std::getline(std::cin, input);
		this->contacts[this->index].setFirstName(input);
	}
	std::cout << "\033[1;36mEnter last name: \033[0m";
	clearerr(stdin);
	std::cin.clear();
	std::getline(std::cin, input);
	this->contacts[this->index].setLastName(input);
	while (this->contacts[this->index].getLastName().empty())
	{
		std::cout << "CAN'T BE EMPTY" << std::endl;
		std::cout << "\033[1;36mEnter last name: \033[0m";
		clearerr(stdin);
		std::cin.clear();
		std::getline(std::cin, input);
		this->contacts[this->index].setLastName(input);
	}
	std::cout << "\033[1;36mEnter nickname: \033[0m";
	std::getline(std::cin, input);
	clearerr(stdin);
	this->contacts[this->index].setNickname(input);
	while (this->contacts[this->index].getNickname().empty())
	{
		std::cout << "CAN'T BE EMPTY" << std::endl;
		std::cout << "\033[1;36mEnter nickname: \033[0m";
		std::getline(std::cin, input);
		clearerr(stdin);
		this->contacts[this->index].setNickname(input);
	}
	std::cout << "\033[1;36mEnter phone number: \033[0m";
	clearerr(stdin);
	std::cin.clear();
	std::getline(std::cin, input);
	this->contacts[this->index].setPhoneNumber(input);
	while (this->contacts[this->index].getPhoneNumber().empty())
	{
		std::cout << "CAN'T BE EMPTY" << std::endl;
		std::cout << "\033[1;36mEnter phone number: \033[0m";
		clearerr(stdin);
		std::cin.clear();
		std::getline(std::cin, input);
		this->contacts[this->index].setPhoneNumber(input);
	}
	std::cout << "\033[1;36mEnter darkest secret: \033[0m";
	clearerr(stdin);
	std::cin.clear();
	std::getline(std::cin, input);
	this->contacts[this->index].setDarkestSecret(input);
	while (this->contacts[this->index].getDarkestSecret().empty())
	{
		std::cout << "CAN'T BE EMPTY" << std::endl;
		std::cout << "\033[1;36mEnter darkest secret: \033[0m";
		clearerr(stdin);
		std::cin.clear();
		std::getline(std::cin, input);
		this->contacts[this->index].setDarkestSecret(input);
	}
	this->index++;
	if (this->contactCount < 7)
		this->contactCount++;
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

void	PhoneBook::printIndex(int i)
{
	if (i < 0 || i > 7)
	{
		std::cout << "Invalid index" << std::endl;
		return ;
	}
	std::cout << "First name: " << this->contacts[i].getFirstName() << std::endl;
	std::cout << "Last name: " << this->contacts[i].getLastName() << std::endl;
	std::cout << "Nickname: " << this->contacts[i].getNickname() << std::endl;
	std::cout << "Phone number: " << this->contacts[i].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << this->contacts[i].getDarkestSecret() << std::endl;
}

void	PhoneBook::printContacts()
{
	int i = 0;
	std::string input;

	if (this->contactCount == -1)
	{
		std::cout << "No contacts" << std::endl;
		return ;
	}
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << "     Index|First name| Last name|  Nickname" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	while (i < this->contactCount + 1)
	{
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << getTrunString(this->contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << getTrunString(this->contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << getTrunString(this->contacts[i].getNickname()) << std::endl;
		i++;
	}
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << "\033[1;35mEnter an index: \033[0m";
	clearerr(stdin);
	std::cin.clear();
	std::getline(std::cin, input);
	while ((input.length() > 1 || input[0] < '0' || input[0] > this->contactCount + '0'))
	{
		std::cout << "Invalid index" << std::endl;
		std::cout << "\033[35mEnter an index: \033[0m";
		clearerr(stdin);
		std::cin.clear();
		std::getline(std::cin, input);
		clearerr(stdin);
	}
	i = input[0] - '0';
	printIndex(i);
}
