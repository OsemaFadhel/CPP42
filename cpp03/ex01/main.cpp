/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:17:43 by ofadhel           #+#    #+#             */
/*   Updated: 2024/03/12 21:47:17 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main()
{
	ScavTrap	ScavTrap("ScavTrap");
	ClapTrap	ClapTrap("ClapTrap");

	ClapTrap.attack("Target");
	ClapTrap.takeDamage(5);
	ClapTrap.beRepaired(5);
	ScavTrap.attack("Target");
	ScavTrap.takeDamage(5);
	ScavTrap.beRepaired(5);
	ScavTrap.guardGate();
	return (0);
}
