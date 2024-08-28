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
 * @brief Main function to test serialization and deserialization.
 *
 * @return int Exit status.
 */
int main() {
	/// Test Case 1: Simple data structure
	Data* original = new Data();
	original->name = "Alice";
	original->age = 30;
	original->salary = 50000.0;

	/// Serialize the original data structure
	uintptr_t raw = Serializer::serialize(original);
	std::cout << "Serialized uintptr_t: " << raw << std::endl;

	/// Deserialize back to Data pointer
	Data* deserialized = Serializer::deserialize(raw);
	std::cout << "Deserialized Data - Name: " << deserialized->name << ", Age: " << deserialized->age << ", Salary: " << deserialized->salary << std::endl;

	/// Check if deserialization was successful
	if (original == deserialized) {
		std::cout << "Test Case 1 Passed: Original and deserialized pointers match." << std::endl;
	} else {
		std::cout << "Test Case 1 Failed: Original and deserialized pointers do not match." << std::endl;
	}

	std::cout << std::endl;

	/// Additional Test Cases
	/// Test Case 2: Edge case with empty string and zero values
	Data* emptyData = new Data();
	emptyData->name = "";
	emptyData->age = 0;
	emptyData->salary = 0.0;

	raw = Serializer::serialize(emptyData);
	deserialized = Serializer::deserialize(raw);
	std::cout << "Deserialized Data - Name: " << deserialized->name << ", Age: " << deserialized->age << ", Salary: " << deserialized->salary << std::endl;
	if (emptyData == deserialized) {
		std::cout << "Test Case 2 Passed: Original and deserialized pointers match." << std::endl;
	} else {
		std::cout << "Test Case 2 Failed: Original and deserialized pointers do not match." << std::endl;
	}

	std::cout << std::endl;

	/// Test Case 3: Large values
	Data* largeData = new Data();
	largeData->name = "Bob";
	largeData->age = 2147483647;
	largeData->salary = 1e10;

	raw = Serializer::serialize(largeData);
	deserialized = Serializer::deserialize(raw);
	std::cout << "Deserialized Data - Name: " << deserialized->name << ", Age: " << deserialized->age << ", Salary: " << deserialized->salary << std::endl;
	if (largeData == deserialized) {
		std::cout << "Test Case 3 Passed: Original and deserialized pointers match." << std::endl;
	} else {
		std::cout << "Test Case 3 Failed: Original and deserialized pointers do not match." << std::endl;
	}

	std::cout << std::endl;

	/// Test Case 4: Special characters in the string
	Data* specialCharData = new Data();
	specialCharData->name = "John\nDoe";
	specialCharData->age = 42;
	specialCharData->salary = 12345.67;

	raw = Serializer::serialize(specialCharData);
	deserialized = Serializer::deserialize(raw);
	std::cout << "Deserialized Data - Name: " << deserialized->name << ", Age: " << deserialized->age << ", Salary: " << deserialized->salary << std::endl;
	if (specialCharData == deserialized) {
		std::cout << "Test Case 4 Passed: Original and deserialized pointers match." << std::endl;
	} else {
		std::cout << "Test Case 4 Failed: Original and deserialized pointers do not match." << std::endl;
	}

	/// Clean up dynamically allocated memory
	delete original;
	delete emptyData;
	delete largeData;
	delete specialCharData;

	return 0;
}
