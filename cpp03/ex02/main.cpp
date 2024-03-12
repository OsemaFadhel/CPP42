/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:17:43 by ofadhel           #+#    #+#             */
/*   Updated: 2024/03/12 22:05:30 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
	ClapTrap	ClapTrap("ClapTrap");
	ScavTrap	ScavTrap("ScavTrap");
	FragTrap	FragTrap("FragTrap");

	ClapTrap.attack("ScavTrap");
	ScavTrap.attack("ClapTrap");
	ScavTrap.guardGate();
	ClapTrap.takeDamage(20);
	FragTrap.attack("ClapTrap");
	ClapTrap.attack("FragTrap");
	ClapTrap.takeDamage(20);
	FragTrap.takeDamage(20);
	ClapTrap.beRepaired(10);
	FragTrap.beRepaired(10);
	FragTrap.attack("ClapTrap");
	return (0);
}
