/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:24:24 by ofadhel           #+#    #+#             */
/*   Updated: 2024/01/28 17:43:25 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Aanimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Aanimal* j = new Dog();
	const Aanimal* i = new Cat();
	delete j;
	delete i;

	return 0;
}
