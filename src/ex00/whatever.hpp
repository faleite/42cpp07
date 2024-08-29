/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:33:12 by faaraujo          #+#    #+#             */
/*   Updated: 2024/08/29 21:11:46 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template <typename T>
T& max(T &a, T &b)
{
	return ((a > b) ? a : b);	
}

template <typename T>
T& min(T &a, T &b)
{
	return ((a < b) ? a : b);	
}

template <typename T>
void swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

#endif // WHATEVER_HPP