/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:46:04 by rjeong            #+#    #+#             */
/*   Updated: 2024/08/15 16:46:06 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/**
 * @brief Main function to test the Serializer class.
 *
 * @return int Exit status.
 */
int main() {
	/// Create an instance of Data structure and initialize it
	Data originalData;
	originalData.n = 42;
	originalData.str = "Hello, World!";

	/// Serialize the address of the Data structure
	uintptr_t serializedData = Serializer::serialize(&originalData);

	/// Deserialize the serialized data back to the original pointer
	Data* deserializedData = Serializer::deserialize(serializedData);

	/// Check if the deserialized data is the same as the original data
	if (deserializedData == &originalData) {
		/// Print success message if serialization and deserialization worked
		std::cout << "Serialization and deserialization successful!" << std::endl;
		/// Print the contents of the deserialized data
		std::cout << "Data: " << deserializedData->n << ", " << deserializedData->str << std::endl;
	} else {
		/// Print an error message if serialization or deserialization failed
		std::cerr << "Serialization or deserialization failed!" << std::endl;
	}

	/// Exit successfully
	return 0;
}
