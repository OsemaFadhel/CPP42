/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:24:21 by ofadhel           #+#    #+#             */
/*   Updated: 2024/01/20 23:40:16 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contactClass.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

std::string Contact::getFirstName() const
{
	return (this->firstName);
}

void	Contact::setFirstName(std::string first_name)
{
	this->firstName = first_name;
}

std::string Contact::getLastName() const
{
	return (this->lastName);
}

void	Contact::setLastName(std::string last_name)
{
	this->lastName = last_name;
}

std::string Contact::getNickname() const
{
	return (this->nickname);
}


void	Contact::setNickname(std::string nickname)
{
	this->nickname = nickname;
}

std::string Contact::getPhoneNumber() const
{
	return (this->phoneNumber);
}

void	Contact::setPhoneNumber(std::string phone_number)
{
	this->phoneNumber = phone_number;
}

std::string Contact::getDarkestSecret() const
{
	return (this->darkestSecret);
}

void	Contact::setDarkestSecret(std::string darkest_secret)
{
	this->darkestSecret = darkest_secret;
}
