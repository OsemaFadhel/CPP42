/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:17:43 by ofadhel           #+#    #+#             */
/*   Updated: 2024/01/26 15:11:58 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main()
{
	ClapTrap	ClapTrap("Human");
	FragTrap	FragTrap("Robot");

	FragTrap.attack("Human");
	ClapTrap.attack("Robot");
	ClapTrap.takeDamage(20);
	FragTrap.takeDamage(20);
	ClapTrap.beRepaired(10);
	FragTrap.beRepaired(10);
	FragTrap.highFivesGuys();
	return (0);
}
