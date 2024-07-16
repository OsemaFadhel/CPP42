/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:37:49 by ofadhel           #+#    #+#             */
/*   Updated: 2024/07/16 15:42:05 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {
	// Create a Data object
	Data originalData;
	originalData.id = 16813;
	originalData.name = "Test";

	// Serialize the Data object's pointer
	uintptr_t serialized = Serializer::serialize(&originalData);
	std::cout << "Serialized value: " << serialized << std::endl;

	// Deserialize the serialized value back to a Data* pointer
	Data* deserializedData = Serializer::deserialize(serialized);

	// Verify that the deserialized pointer matches the original pointer
	if (deserializedData == &originalData) {
		std::cout << "Deserialization successful." << std::endl;
		std::cout << "Deserialized Data: id = " << deserializedData->id << ", name = " << deserializedData->name << std::endl;
	} else {
		std::cout << "Deserialization failed." << std::endl;
	}

	return 0;
}
