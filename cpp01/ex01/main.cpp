/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:12:54 by ofadhel           #+#    #+#             */
/*   Updated: 2024/02/02 14:14:28 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int N = 5;
	Zombie* horde = zombieHorde(N, "marco");
	for (int i = 0; i < N; i++)
	{
		horde[i].announce();
	}
	delete [] horde;
	return (0);
}
