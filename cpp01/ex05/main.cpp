/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:12:57 by ofadhel           #+#    #+#             */
/*   Updated: 2024/02/02 15:46:49 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl	harl;
	std::string	level;

	while (1)
	{
		std::cout << "Enter the level of your complaint (DEBUG, INFO, WARNING, ERROR): ";
		std::getline(std::cin, level);
		if (std::cin.eof())
			break ;
		if (level == "EXIT")
			break ;
		harl.complain(level);
	}
}
