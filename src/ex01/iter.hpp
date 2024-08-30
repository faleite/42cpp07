/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 17:15:58 by faaraujo          #+#    #+#             */
/*   Updated: 2024/08/30 19:22:20 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

/*
 ANOTHER FORMS: 
 void iter(T &array, size_t length, F &func)
 void iter(T *array, size_t length, F func)
 void iter(T *arr, int len, void (*func)(T &))
 void iter(T const *arr, int len, void (*func)(const T &))
*/
template <typename T, typename F>
void iter(T array[], size_t length, F &func)
{
	for (size_t i = 0; i < length; i++)
		func(array[i]);
}

#endif // ITER_HPP