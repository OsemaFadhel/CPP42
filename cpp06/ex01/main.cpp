/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:37:49 by ofadhel           #+#    #+#             */
/*   Updated: 2024/07/17 12:36:19 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {
	Data originalData;
	originalData.id = 16813;
	originalData.name = "Test";

	uintptr_t serialized = Serializer::serialize(&originalData);
	std::cout << "Serialized value: " << serialized << std::endl;

	Data* deserializedData = Serializer::deserialize(serialized);

	if (deserializedData == &originalData)
	{
		std::cout << "Deserialization successful." << std::endl;
		std::cout << "Deserialized Data: id = " << deserializedData->id << ", name = " << deserializedData->name << std::endl;
	}
	else
	{
		std::cout << "Deserialization failed." << std::endl;
	}

	return 0;
}
