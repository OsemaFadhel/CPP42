/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Aanimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:30:03 by ofadhel           #+#    #+#             */
/*   Updated: 2024/01/28 17:42:40 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Aanimal.hpp"

Aanimal::Aanimal()
{
	std::cout << "Aanimal constructor called" << std::endl;
}

Aanimal::Aanimal(std::string type)
{
	this->type = type;
	std::cout << "Aanimal constructor called" << std::endl;
}

Aanimal::Aanimal(Aanimal const &src)
{
	std::cout << "Aanimal copy constructor called" << std::endl;
	*this = src;
}

Aanimal &Aanimal::operator=(Aanimal const &src)
{
	std::cout << "Aanimal assignation operator called" << std::endl;
	this->type = src.type;
	return (*this);
}

Aanimal::~Aanimal()
{
	std::cout << "Aanimal destructor called" << std::endl;
}

std::string Aanimal::getType() const
{
	return (this->type);
}

/*void Aanimal::makeSound() const
{
	std::cout << "Aanimal sound" <<  std::endl;
}*/
