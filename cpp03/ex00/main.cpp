/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:17:15 by ofadhel           #+#    #+#             */
/*   Updated: 2024/01/25 15:25:52 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	ClapTrap("Giuseppe");

	ClapTrap.attack("Mario");
	ClapTrap.takeDamage(5);
	ClapTrap.beRepaired(5);
	return (0);
}
