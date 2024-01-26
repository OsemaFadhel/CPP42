/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:17:43 by ofadhel           #+#    #+#             */
/*   Updated: 2024/01/26 14:56:29 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main()
{
	ScavTrap	ScavTrap("ScavTrap");

	ScavTrap.attack("Target");
	ScavTrap.takeDamage(5);
	ScavTrap.beRepaired(5);
	ScavTrap.guardGate();
	return (0);
}