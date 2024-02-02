/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:12:57 by ofadhel           #+#    #+#             */
/*   Updated: 2024/02/02 16:59:03 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl	harl;
	std::string	level;

	if (argc == 2)
		harl.complain(argv[1]);
	else
	{
		std::cout << "ERROR" << std::endl;
		return (1);
	}
	return (0);
}
