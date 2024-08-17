/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 10:57:32 by rjeong            #+#    #+#             */
/*   Updated: 2024/08/23 10:57:33 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

/**
 * @brief The Base class is an abstract class with a virtual destructor.
 * It serves as the base class for A, B, and C.
 */
class Base {
	public:
		/**
		 * @brief Virtual destructor to ensure proper cleanup of derived classes.
		 */
		virtual ~Base();
};

#endif
