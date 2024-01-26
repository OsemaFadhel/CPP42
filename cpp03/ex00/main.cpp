/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:17:15 by ofadhel           #+#    #+#             */
/*   Updated: 2024/01/26 14:50:19 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	ClapTrap("ClapTrack");

	ClapTrap.attack("Target");
	ClapTrap.takeDamage(5);
	ClapTrap.beRepaired(5);
	return (0);
}
