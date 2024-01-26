/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:36:05 by ofadhel           #+#    #+#             */
/*   Updated: 2024/01/26 18:01:50 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(std::string type) : Animal(type)
{
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(Cat const &src)
{
	std::cout << "Cat Copy constructor called" << std::endl;
	*this = src;
}

Cat &Cat::operator=(Cat const &src)
{
	std::cout << "Cat Assignation operator called" << std::endl;
	if (this != &src)
		this->type = src.type;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}
