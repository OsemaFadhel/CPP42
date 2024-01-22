/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:45:33 by ofadhel           #+#    #+#             */
/*   Updated: 2024/01/22 18:03:32 by ofadhel          ###   ########.fr       */
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
		Zombie( std::string name );
		~Zombie();
		void announce( void );
		Zombie* newZombie( std::string name );
		void randomChump( std::string name );
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif
