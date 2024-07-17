/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:52:43 by ofadhel           #+#    #+#             */
/*   Updated: 2024/07/17 12:35:10 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

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

int main()
{
	Base *base = generate();

	identify(base);
	identify(*base);
	delete base;
	return 0;
}
