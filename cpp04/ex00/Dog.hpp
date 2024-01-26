/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:53:40 by ofadhel           #+#    #+#             */
/*   Updated: 2024/01/26 17:58:51 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Dog_HPP
# define Dog_HPP

#include "Animal.hpp"

class Dog : virtual public Animal
{
	public:
		Dog();
		Dog(std::string type);
		Dog(Dog const &src);
		Dog &operator=(Dog const &src);
		~Dog();
};

#endif
