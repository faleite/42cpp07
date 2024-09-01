/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 14:00:39 by faaraujo          #+#    #+#             */
/*   Updated: 2024/09/01 15:01:02 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.tpp"


/*
Por que Funciona com Tipos Simples e Complexos?

Generalidade:
- A class template é definida com um parâmetro de tipo genérico T. 
Isso significa que T pode ser qualquer tipo de dado, seja ele um tipo primitivo 
(como int, float, etc.) ou um tipo complexo (como std::string, std::vector, 
ou até mesmo uma classe definida pelo usuário).

Operador de Atribuição:
- O operador de atribuição (operator=) é implementado de forma a copiar cada 
elemento do array de origem para o array de destino. Isso funciona para 
qualquer tipo T que tenha um operador de atribuição definido.
- Para tipos primitivos, o operador de atribuição padrão é usado.
- Para tipos complexos, o operador de atribuição definido pelo usuário ou 
o gerado pelo compilador é usado.

Alocação Dinâmica:
- A memória para o array é alocada dinamicamente usando new T[size]. 
Isso funciona para qualquer tipo T que possa ser alocado dinamicamente.
- O destrutor (~Array()) libera a memória alocada, garantindo que não haja 
vazamentos de memória.

Acesso aos Elementos:
- O operador de indexação (operator[]) permite acessar e modificar os elementos 
do array. Isso funciona para qualquer tipo T que suporte acesso por índice.
*/
int	main(void)
{
	std::cout << "\n=========== Type of integer ==============\n\n";
	{
		::Array<int> arrEmpty;
		::Array<int> arrForCopy(50);
		::Array<int> arrNumbers;
		arrNumbers = arrForCopy;
	
		std::cout << "\nSize of Array arrEmpty: " << arrEmpty.size() << std::endl;
		
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
		std::cout << std::endl;
	}
	std::cout << "\n=========== Type of string ===============\n\n";
	{
		::Array<std::string> arrStrings(5);
		std::cout << "\nSize of Array arrStrings: " << arrStrings.size() << std::endl;
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
		std::cout << std::endl << std::endl;
	}
	return (0);
}

#define MAX_VAL 750

int main1(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//

	// My tests
	{
		const int value = (rand() % MAX_VAL);
		std::cout << "The size of numbers: " << numbers.size() << std::endl;
		std::cout << "Get a numbers on index " << value 
		<< ": " << numbers[value] << std::endl;
	
		/*
		std::cout << "Getting numbers of numbers: " << std::endl;
		for (size_t i = 0; i < MAX_VAL; i++)
			std::cout << numbers[i] << " ";
		std::cout << std::endl;
		*/
	}

    return 0;
}
