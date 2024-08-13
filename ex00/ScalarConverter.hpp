/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 02:55:58 by rjeong            #+#    #+#             */
/*   Updated: 2024/08/14 02:55:59 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <cstdlib>

/**
 * @brief The ScalarConverter class provides a static method to convert a string
 * literal to different scalar types (char, int, float, double).
 */
class ScalarConverter {
	public:
		/**
		 * @brief Converts the given string literal to char, int, float, and double types,
		 * and prints the results.
		 *
		 * @param literal The string literal to convert.
		 */
		static void convert(const std::string& literal);

	private:
		/**
		 * @brief Private constructor to prevent instantiation of the class.
		 */
		ScalarConverter();

		/**
		 * @brief Private destructor.
		 */
		~ScalarConverter();

		/**
		 * @brief Converts the given value to char and prints it.
		 *
		 * @param value The value to convert to char.
		 */
		static void convertToChar(double value);

		/**
		 * @brief Converts the given value to int and prints it.
		 *
		 * @param value The value to convert to int.
		 */
		static void convertToInt(double value);

		/**
		 * @brief Converts the given value to float and prints it.
		 *
		 * @param value The value to convert to float.
		 */
		static void convertToFloat(double value);

		/**
		 * @brief Converts the given value to double and prints it.
		 *
		 * @param value The value to convert to double.
		 */
		static void convertToDouble(double value);

		/**
		 * @brief Checks if the literal is a char.
		 *
		 * @param literal The string literal to check.
		 * @return True if the literal is a char, otherwise false.
		 */
		static bool isCharLiteral(const std::string& literal);

		/**
		 * @brief Checks if the literal is an int.
		 *
		 * @param literal The string literal to check.
		 * @return True if the literal is an int, otherwise false.
		 */
		static bool isIntLiteral(const std::string& literal);

		/**
		 * @brief Checks if the literal is a float.
		 *
		 * @param literal The string literal to check.
		 * @return True if the literal is a float, otherwise false.
		 */
		static bool isFloatLiteral(const std::string& literal);

		/**
		 * @brief Checks if the literal is a double.
		 *
		 * @param literal The string literal to check.
		 * @return True if the literal is a double, otherwise false.
		 */
		static bool isDoubleLiteral(const std::string& literal);
};

#endif
