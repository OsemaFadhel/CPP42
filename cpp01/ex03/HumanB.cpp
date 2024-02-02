/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:29:45 by ofadhel           #+#    #+#             */
/*   Updated: 2024/02/02 14:42:28 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name)
{
}

HumanB::~HumanB()
{
}

void	HumanB::attack()
{
	if (this->weapon != NULL && this->weapon->getType() != "")
		std::cout << name << " attacks with their " << this->weapon->getType() << std::endl;
	else
		std::cout << name << " attacks barehands" << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
