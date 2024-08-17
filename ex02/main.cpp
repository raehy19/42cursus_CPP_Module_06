/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 10:58:09 by rjeong            #+#    #+#             */
/*   Updated: 2024/08/23 10:58:10 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Identify.hpp"

/**
 * @brief Main function to test the identification of object types.
 *
 * @return int Exit status.
 */
int main() {
	/// Seed the random number generator
	std::srand(static_cast<unsigned int>(std::time(0)));

	/// Generate a random object
	Base* obj = generate();

	/// Identify the type of the object using a pointer
	identify(obj);

	/// Identify the type of the object using a reference
	identify(*obj);

	/// Clean up memory by deleting the object
	delete obj;

	/// Return success status
	return 0;
}
