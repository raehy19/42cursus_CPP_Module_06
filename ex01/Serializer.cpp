/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:46:16 by rjeong            #+#    #+#             */
/*   Updated: 2024/08/15 16:46:17 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/**
 * @brief Default constructor.
 * Private to prevent instantiation.
 */
Serializer::Serializer() {}

/**
 * @brief Destructor.
 * Nothing to clean up, so it's empty.
 */
Serializer::~Serializer() {}

/**
 * @brief Serializes a pointer to the Data structure into an unsigned integer type.
 *
 * @param ptr Pointer to the Data structure to be serialized.
 * @return Serialized uintptr_t value.
 */
uintptr_t Serializer::serialize(Data* ptr) {
	/// Cast the Data pointer to uintptr_t and return it
	return reinterpret_cast<uintptr_t>(ptr);
}

/**
 * @brief Deserializes an unsigned integer back into a pointer to the Data structure.
 *
 * @param raw The uintptr_t value to be deserialized.
 * @return Deserialized pointer to the Data structure.
 */
Data* Serializer::deserialize(uintptr_t raw) {
	/// Cast the uintptr_t value back to a Data pointer and return it
	return reinterpret_cast<Data*>(raw);
}
