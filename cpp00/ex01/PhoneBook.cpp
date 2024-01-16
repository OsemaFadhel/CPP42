/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:59:25 by ofadhel           #+#    #+#             */
/*   Updated: 2024/01/16 20:58:45 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>

#include "phonebook_class.hpp"
#include "contact_class.hpp"

void	PhoneBook::print()
{
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < this->index; i++)
	{
		std::cout << std::setw(10) << i << "|";
		this->contacts[i].print();
	}
}

void	PhoneBook::add()
{
	if (this->index == 8)
	{
		this->index = 0;
		this->contacts[this->index].add();
		this->index++;
	}
	else
	{
		this->contacts[this->index].add();
		this->index++;
	}
}

