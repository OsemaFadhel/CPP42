/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:24:24 by ofadhel           #+#    #+#             */
/*   Updated: 2024/03/15 18:18:06 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	i->makeSound();
	i->getType();

	delete j;
	delete i;

	Animal* array[8];

	for (int i = 0; i < 8; i++)
	{
		if (i % 2 == 0)
		{
			array[i] = new Dog();
			array[i]->makeSound();
			std::cout << array[i]->getType() << std::endl;
			std::cout << "bella " << dynamic_cast< Dog* >(array[i])->getBrainIdea(0) << std::endl;
			dynamic_cast< Dog* >(array[i])->setBrainIdea(0, "Idea");
			std::cout << "bella2 " << dynamic_cast< Dog* >(array[i])->getBrainIdea(0) << std::endl;
		}
		else
		{
			array[i] = new Cat();
			array[i]->makeSound();
			std::cout << array[i]->getType() << std::endl;
		}
	}

	for (int i = 0; i < 8; i++)
	{
		delete array[i];
	}

	return 0;
}
