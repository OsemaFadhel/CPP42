/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:45:33 by ofadhel           #+#    #+#             */
/*   Updated: 2024/01/22 19:08:50 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	private:
		std::string name;
	public:
		Zombie();
		~Zombie();
		void announce( void );
		Zombie* zombieHorde( int N, std::string name );
		void	setName(std::string name);
};

Zombie* zombieHorde( int N, std::string name );

#endif
