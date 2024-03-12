/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:34:44 by ofadhel           #+#    #+#             */
/*   Updated: 2024/03/12 22:20:12 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	this->name = name;
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &C)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = C;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &C)
{
	std::cout << "ScavTrap assignation operator called" << std::endl;
	this->name = C.name;
	this->hitPoints = C.hitPoints;
	this->energyPoints = C.energyPoints;
	this->attackDamage = C.attackDamage;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(std::string const & target)
{
	if (energyPoints > 0)
	{
		this->energyPoints -= 1;
		std::cout << "ScavTrap " << this->name << " attack " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ScavTrap " << this->name << " has no energy" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap is in Gate keeper mode" << std::endl;
}
