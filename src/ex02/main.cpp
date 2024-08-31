/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 14:00:39 by faaraujo          #+#    #+#             */
/*   Updated: 2024/08/31 17:12:29 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int	main(void)
{
	std::cout << "\n=========== Type of integer ==============\n\n";
	{
		::Array<int> arrEmpty;
		::Array<int> arrForCopy(50);
		::Array<int> arrNumbers;
		arrNumbers = arrForCopy;
	
		std::cout << "Size of Array arrEmpty: " << arrEmpty.size() << std::endl;
		
		try
		{
			std::cout << "Size of Array arrNumbers: " << arrNumbers.size() << std::endl;
			for (size_t i = 0; i < 50; i++)
				arrNumbers[i] = i;
				
			std::cout << "Getting Numbers of arrNumbers: " << std::endl;
			for (size_t i = 0; i < 50; i++)
				std::cout << arrNumbers[i] << " ";
			std::cout << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			std::cout << arrNumbers[-1] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "\n=========== Type of string ===============\n\n";
	{
		::Array<std::string> arrStrings(5);
		std::cout << "Size of Array arrStrings: " << arrStrings.size() << std::endl;
		try
		{
			arrStrings[-1] = "Empty";
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << ": (arrStrings[-1])" << std::endl;
		}
		arrStrings[0] = "Class";
		arrStrings[1] = "template";
		arrStrings[2] = "Array";
		arrStrings[3] = "contains";
		arrStrings[4] = "elements of type string now";

		std::cout << "Getting elements of arrStrings: " << std::endl;
		for (size_t i = 0; i < 5; i++)
			std::cout << arrStrings[i] << " ";
		std::cout << std::endl;
	}
	
	return (0);
}