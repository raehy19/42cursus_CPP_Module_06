/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 10:57:35 by rjeong            #+#    #+#             */
/*   Updated: 2024/08/23 10:57:37 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IDENTIFY_HPP
#define IDENTIFY_HPP

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>

/**
 * @brief Generates a random instance of A, B, or C, and returns it as a Base pointer.
 *
 * @return Base* Pointer to the randomly generated instance.
 */
Base* generate(void);

/**
 * @brief Identifies the actual type of the object pointed to by p (using pointer).
 *
 * @param p Pointer to the Base object.
 */
void identify(Base* p);

/**
 * @brief Identifies the actual type of the object pointed to by p (using reference).
 *
 * @param p Reference to the Base object.
 */
void identify(Base& p);

#endif
