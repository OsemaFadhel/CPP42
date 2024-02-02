/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:30:57 by ofadhel           #+#    #+#             */
/*   Updated: 2024/02/02 14:33:20 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string type )
{
	this->type = type;
}

Weapon::~Weapon()
{
	return ;
}

std::string Weapon::getType() const
{
	return (this->type);
}

void Weapon::setType( std::string type )
{
	this->type = type;
}
