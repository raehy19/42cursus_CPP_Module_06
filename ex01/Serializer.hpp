/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:46:11 by rjeong            #+#    #+#             */
/*   Updated: 2024/08/15 16:46:11 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

/**
 * @brief The Data structure contains the data to be serialized and deserialized.
 */
struct Data {
	int         n;        ///< Example integer data
	std::string str;      ///< Example string data
};

/**
 * @brief The Serializer class provides functionality to serialize and deserialize
 * pointers to the Data structure.
 */
class Serializer {
	public:
		/**
		 * @brief Serializes a pointer to the Data structure into an unsigned integer type.
		 *
		 * @param ptr Pointer to the Data structure to be serialized.
		 * @return Serialized uintptr_t value.
		 */
		static uintptr_t serialize(Data* ptr);

		/**
		 * @brief Deserializes an unsigned integer back into a pointer to the Data structure.
		 *
		 * @param raw The uintptr_t value to be deserialized.
		 * @return Deserialized pointer to the Data structure.
		 */
		static Data* deserialize(uintptr_t raw);

	private:
		/**
		 * @brief Private constructor to prevent instantiation of the class.
		 */
		Serializer();

		/**
		 * @brief Private destructor.
		 */
		~Serializer();
};

#endif
