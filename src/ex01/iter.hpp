/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 17:15:58 by faaraujo          #+#    #+#             */
/*   Updated: 2024/09/01 15:08:56 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

/*
 ANOTHER FORMS: 
 void iter(T &array, size_t length, F &func)
 void iter(T array[], size_t length, F func)
 void iter(T *array, int length, void (*func)(T &))
 void iter(T const *array, int length, void (*func)(const T &))
*/
template <typename T, typename F>
void iter(T *array, size_t length, F &func)
{
	for (size_t i = 0; i < length; i++)
		func(array[i]);
}

#endif // ITER_HPP