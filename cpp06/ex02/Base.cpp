/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:45:02 by ofadhel           #+#    #+#             */
/*   Updated: 2024/07/16 16:05:21 by ofadhel          ###   ########.fr       */
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

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base &p)
{
	try {
		A& a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	} catch (const std::bad_cast&) {}
	try {
		B& b = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	}
	catch (const std::bad_cast&) {}
	try {
		C& c = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	}
	catch (const std::bad_cast&) {}
}
