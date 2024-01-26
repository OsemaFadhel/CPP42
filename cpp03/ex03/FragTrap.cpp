/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:03:01 by ofadhel           #+#    #+#             */
/*   Updated: 2024/01/26 16:10:43 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap constructor called" << std::endl;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap(std::string name)
{
	this->name = name;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &C)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = C;
}

FragTrap &FragTrap::operator=(const FragTrap &C)
{
	std::cout << "FragTrap assignation operator called" << std::endl;
	this->name = C.name;
	this->hitPoints = C.hitPoints;
	this->energyPoints = C.energyPoints;
	this->attackDamage = C.attackDamage;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

void	FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << this->name << " wants to high five" << std::endl;
}
