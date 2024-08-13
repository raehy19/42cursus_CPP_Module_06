/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 02:56:42 by rjeong            #+#    #+#             */
/*   Updated: 2024/08/14 02:56:43 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/**
 * @brief Main function to test the ScalarConverter class.
 *
 * @param argc Number of command-line arguments.
 * @param argv Array of command-line arguments.
 * @return int Exit status.
 */
int main(int argc, char* argv[]) {
	/// Check if exactly one argument is provided, otherwise show usage
	if (argc != 2) {
		/// Print usage instructions
		std::cerr << "Usage: " << argv[0] << " <literal>" << std::endl;
		/// Return with error code 1
		return 1;
	}

	/// Convert the provided literal
	ScalarConverter::convert(argv[1]);
	/// Return with success code 0
	return 0;
}
