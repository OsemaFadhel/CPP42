/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:53:47 by ofadhel           #+#    #+#             */
/*   Updated: 2024/01/22 19:10:02 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( )
{
	return ;
}

Zombie::~Zombie()
{
	return ;
}

void Zombie::announce( void )
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}


void	Zombie::setName(std::string name)
{
	this->name = name;
}
