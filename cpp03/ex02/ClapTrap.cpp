/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:29:08 by ofadhel           #+#    #+#             */
/*   Updated: 2024/03/12 22:18:34 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name)
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &C)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = C;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &C)
{
	std::cout << "ClapTrap assignation operator called" << std::endl;
	this->name = C.name;
	this->hitPoints = C.hitPoints;
	this->energyPoints = C.energyPoints;
	this->attackDamage = C.attackDamage;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (energyPoints > 0)
	{
		this->energyPoints -= 1;
		std::cout << "ClapTrap " << this->name << " attack " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->name << " has no energy" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints > 0)
	{
		this->hitPoints -= amount;
		std::cout << "ClapTrap " << this->name << " takes " << amount << " damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->name << " is dead" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints > 0 && energyPoints > 0)
	{
		this->energyPoints -= 1;
		this->hitPoints += amount;
		std::cout << "ClapTrap " << this->name << " is repairing " << amount << " points!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->name << " has no energy" << std::endl;
}
