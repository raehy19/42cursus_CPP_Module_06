/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 02:55:49 by rjeong            #+#    #+#             */
/*   Updated: 2024/08/14 02:55:51 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/**
 * @brief Default constructor.
 * Private to prevent instantiation.
 */
ScalarConverter::ScalarConverter() {}

/**
 * @brief Destructor.
 * Nothing to clean up, so it's empty.
 */
ScalarConverter::~ScalarConverter() {}

/**
 * @brief Converts the string literal to various scalar types and prints the results.
 *
 * @param literal The string literal to convert.
 */
void ScalarConverter::convert(const std::string& literal) {
	/// Initialize value as double
	double value = 0.0f;

	/// Check if the literal is a char type
	if (isCharLiteral(literal)) {
		/// Convert char to double
		value = static_cast<double>(literal[0]);
	}
		/// Check if the literal is an int type
	else if (isIntLiteral(literal)) {
		/// Convert string to long and assign to value
		value = static_cast<double>(std::strtol(literal.c_str(), NULL, 10));
	}
		/// Check if the literal is a float type
	else if (isFloatLiteral(literal)) {
		/// Convert string to float and cast to double
		value = static_cast<double>(std::strtof(literal.c_str(), NULL));
	}
		/// Check if the literal is a double type
	else if (isDoubleLiteral(literal)) {
		/// Convert string to double
		value = std::strtod(literal.c_str(), NULL);
	}
		/// If the literal type is unknown
	else {
		/// Print error message for unknown type
		std::cerr << "Error: Unknown literal type." << std::endl;
		/// Exit function
		return;
	}

	/// Convert and print the value as char
	convertToChar(value);
	/// Convert and print the value as int
	convertToInt(value);
	/// Convert and print the value as float
	convertToFloat(value);
	/// Convert and print the value as double
	convertToDouble(value);
}

/**
 * @brief Converts and prints the value as a char.
 *
 * @param value The value to convert.
 */
void ScalarConverter::convertToChar(double value) {
	/// Print char label
	std::cout << "char: ";

	/// Check if the value is out of char range or NaN
	if (value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max() || std::isnan(value)) {
		/// Print "impossible" if conversion is not possible
		std::cout << "impossible" << std::endl;
	}
		/// Check if the character is not displayable
	else if (!isprint(static_cast<int>(value))) {
		/// Print "Non displayable" if char is non-printable
		std::cout << "Non displayable" << std::endl;
	}
		/// If the character is printable
	else {
		/// Print the character
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
	}
}

/**
 * @brief Converts and prints the value as an int.
 *
 * @param value The value to convert.
 */
void ScalarConverter::convertToInt(double value) {
	/// Print int label
	std::cout << "int: ";

	/// Check if the value is out of int range or NaN
	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max() || std::isnan(value)) {
		/// Print "impossible" if conversion is not possible
		std::cout << "impossible" << std::endl;
	}
		/// If the value is within range
	else {
		/// Print the integer value
		std::cout << static_cast<int>(value) << std::endl;
	}
}

/**
 * @brief Converts and prints the value as a float.
 *
 * @param value The value to convert.
 */
void ScalarConverter::convertToFloat(double value) {
	/// Print float label
	std::cout << "float: ";

	/// Check if the value is NaN
	if (std::isnan(value)) {
		/// Print "nanf" if value is NaN
		std::cout << "nanf" << std::endl;
	}
		/// Check if the value is infinity
	else if (std::isinf(value)) {
		/// Print "+inff" or "-inff" based on the sign
		std::cout << (value < 0 ? "-inff" : "+inff") << std::endl;
	}
		/// If the value is a normal float
	else {
		/// Print the float value with fixed precision
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
	}
}

/**
 * @brief Converts and prints the value as a double.
 *
 * @param value The value to convert.
 */
void ScalarConverter::convertToDouble(double value) {
	/// Print double label
	std::cout << "double: ";

	/// Check if the value is NaN
	if (std::isnan(value)) {
		/// Print "nan" if value is NaN
		std::cout << "nan" << std::endl;
	}
		/// Check if the value is infinity
	else if (std::isinf(value)) {
		/// Print "+inf" or "-inf" based on the sign
		std::cout << (value < 0 ? "-inf" : "+inf") << std::endl;
	}
		/// If the value is a normal double
	else {
		/// Print the double value with fixed precision
		std::cout << std::fixed << std::setprecision(1) << value << std::endl;
	}
}

/**
 * @brief Checks if the literal is a char.
 *
 * @param literal The string literal to check.
 * @return True if it's a char, false otherwise.
 */
bool ScalarConverter::isCharLiteral(const std::string& literal) {
	/// Return true if the literal has length 1, is printable, and is not a digit
	return literal.length() == 1 && isprint(literal[0]) && !isdigit(literal[0]);
}

/**
 * @brief Checks if the literal is an int.
 *
 * @param literal The string literal to check.
 * @return True if it's an int, false otherwise.
 */
bool ScalarConverter::isIntLiteral(const std::string& literal) {
	/// Declare a pointer for the end of the conversion
	char* end;
	/// Convert the string to long
	long value = std::strtol(literal.c_str(), &end, 10);
	/// Return true if the conversion is valid and within int range
	return *end == '\0' && value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max();
}

/**
 * @brief Checks if the literal is a float.
 *
 * @param literal The string literal to check.
 * @return True if it's a float, false otherwise.
 */
bool ScalarConverter::isFloatLiteral(const std::string& literal) {
	/// Declare a pointer for the end of the conversion
	char* end;
	/// Convert the string to float
	std::strtof(literal.c_str(), &end);
	/// Return true if the conversion ends with 'f'
	return *end == 'f' && *(end + 1) == '\0';
}

/**
 * @brief Checks if the literal is a double.
 *
 * @param literal The string literal to check.
 * @return True if it's a double, false otherwise.
 */
bool ScalarConverter::isDoubleLiteral(const std::string& literal) {
	/// Declare a pointer for the end of the conversion
	char* end;
	/// Convert the string to double
	std::strtod(literal.c_str(), &end);
	/// Return true if the conversion is valid
	return *end == '\0';
}
