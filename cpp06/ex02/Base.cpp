/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:45:02 by ofadhel           #+#    #+#             */
/*   Updated: 2024/07/17 12:35:02 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base() {}

Base *generate(void)
{
	int random = rand() % 3;
	if (random == 0)
		return new A();
	else if (random == 1)
		return new B();
	else
		return new C();
}

