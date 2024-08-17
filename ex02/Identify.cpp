/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 10:58:06 by rjeong            #+#    #+#             */
/*   Updated: 2024/08/23 10:58:08 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"

/**
 * @brief Generates a random instance of A, B, or C, and returns it as a Base pointer.
 *
 * @return Base* Pointer to the randomly generated instance.
 */
Base* generate(void) {
	/// Generate a random number between 0 and 2
	int random = std::rand() % 3;

	/// Return a new instance of A, B, or C based on the random number
	if (random == 0)
		return new A();
	else if (random == 1)
		return new B();
	else
		return new C();
}

/**
 * @brief Identifies the actual type of the object pointed to by p (using pointer).
 *
 * @param p Pointer to the Base object.
 */
void identify(Base* p) {
	/// Check if the object is of type A
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
		/// Check if the object is of type B
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
		/// Check if the object is of type C
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

/**
 * @brief Identifies the actual type of the object pointed to by p (using reference).
 *
 * @param p Reference to the Base object.
 */
void identify(Base& p) {
	try {
		/// Attempt to cast the object to type A
		A& a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		(void)a;  // Avoid unused variable warning
	} catch (const std::bad_cast&) {
		try {
			/// Attempt to cast the object to type B
			B& b = dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
			(void)b;  // Avoid unused variable warning
		} catch (const std::bad_cast&) {
			try {
				/// Attempt to cast the object to type C
				C& c = dynamic_cast<C&>(p);
				std::cout << "C" << std::endl;
				(void)c;  // Avoid unused variable warning
			} catch (const std::bad_cast&) {
				std::cout << "Unknown type" << std::endl;
			}
		}
	}
}
