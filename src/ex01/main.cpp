/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 17:56:33 by faaraujo          #+#    #+#             */
/*   Updated: 2024/09/01 15:07:13 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void printArray(T &d)
{
	std::cout << d << " ";
	return;
}

int	main(void)
{
	int arrInt[] = {23, 10, 84};
	float arrFloat[] = {1.69, 3.14, 7.2};
	std::string arrString[] = {"alpha", "beta", "omega"};
	size_t sizeArr = 3;
	
	std::cout << "Array of Integer:" << std::endl;
	::iter(arrInt, sizeArr, printArray<int>); // Function Template
	std::cout << std::endl;
	
	std::cout << "Array of Float:" << std::endl;
	::iter(arrFloat, sizeArr, printArray<float>); // Function Template
	std::cout << std::endl;
	
	std::cout << "Array of Strings:" << std::endl;
	::iter(arrString, sizeArr, printArray<std::string>); // Function Template
	std::cout << std::endl;

	return (0);
}
