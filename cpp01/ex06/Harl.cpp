/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:30:41 by ofadhel           #+#    #+#             */
/*   Updated: 2024/02/02 17:37:03 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	return ;
}

Harl::~Harl()
{
	return ;
}

void	Harl::complain( std::string level )
{
	complain_t	complains[4] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	std::string			levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	int					j = -1;

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			j = i;
			break ;
		}
	}
	switch (j)
	{
		case 3:
			(this->*complains[j])();
			j--;
		case 2:
			(this->*complains[j])();
			j-- ;
		case 1:
			(this->*complains[j])();
			j--;
		case 0:
			(this->*complains[j])();
			j-- ;
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break ;
	}
}

void Harl::debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl << std::endl;
}

void Harl::info( void )
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl << std::endl;
}

void Harl::warning( void )
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl << std::endl;
}

void Harl::error( void )
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
}
