/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:33:12 by faaraujo          #+#    #+#             */
/*   Updated: 2024/08/30 18:25:42 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

/*
Prefira a versão de referência porque, por exemplo, no caso de uma string 
ou algum contêiner, não quero copiá-lo inteiramente para essas funções, 
é melhor acessá-lo por referência

Além disso, a versão de referência é mais flexível, o compilador pode 
re-referenciar uma referência e atribuí-la a um valor, mas não converterá 
um valor em uma referência a ela.

Então a versão de referência funciona para referências e valores, 
enquanto a versão de valor não.
*/

template <typename T>
T &max(T &a, T &b)
{
	return ((a > b) ? a : b);	
}

template <typename T>
T &min(T &a, T &b)
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