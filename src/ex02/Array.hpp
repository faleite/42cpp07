/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 13:44:46 by faaraujo          #+#    #+#             */
/*   Updated: 2024/09/01 14:47:39 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <string>
#include <cstdlib> // for rand();

/*
Desenvolva um modelo de classe Array que contenha elementos do tipo T e que 
implemente o seguinte comportamento e funções:

- Construção sem parâmetro: Cria um array vazio.
- Construção com um unsigned int n como parâmetro: Cria um array de n elementos 
inicializados por padrão.
Dica: Tente compilar int * a = new int(); então exiba *a.
- Construção por operador de cópia e atribuição. Em ambos os casos, modificar 
o array original ou sua cópia após a cópia não deve afetar o outro array.
- Você DEVE usar o operador new[] para alocar memória. A alocação preventiva 
(alocar memória antecipadamente) é proibida. Seu programa nunca deve acessar 
memória não alocada.
- Elementos podem ser acessados ​​por meio do operador subscrito: [ ].
- Ao acessar um elemento com o operador [ ], se seu índice estiver fora dos 
limites, uma std::exception é lançada.
- Uma função membro size() que retorna o número de elementos no array. 
Esta função membro não aceita parâmetros e não deve modificar a instância atual.
- Como de costume, garanta que tudo funcione conforme o esperado e entregue 
um arquivo main.cpp que contenha seus testes.
*/
template <typename T>
class Array
{
	private:
		size_t _sizeArr;
		T *_array;
	public:
		Array();
		// Array(size_t n);
		Array(unsigned int n);
		Array(const Array<T> &copyObj);
		Array &operator=(const Array<T> &assignCopy);
		T &operator[](const size_t index);
		~Array();

		size_t size() const;
};

// #include "Array.tpp"

#endif // ARRAY_HPP