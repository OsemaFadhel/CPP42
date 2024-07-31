/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:26:11 by ofadhel           #+#    #+#             */
/*   Updated: 2024/07/31 15:51:37 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <stdint.h>
#include "Data.hpp"

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &src);
		Serializer &operator=(const Serializer &src);
		~Serializer();
	public:
		static uintptr_t serialize(Data* ptr); //It takes a pointer and converts it to the unsigned integer type uintptr_t.
		static Data* deserialize(uintptr_t raw); //It takes an unsigned integer parameter and converts it to a pointer to Data
};

#endif
