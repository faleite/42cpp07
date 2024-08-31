/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 13:44:46 by faaraujo          #+#    #+#             */
/*   Updated: 2024/08/31 16:25:42 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

template <typename T>
Array<T>::Array(): _sizeArr(0), _array(0)
{
	std::cout << "Array Default Constructor called" << std::endl;
}

// Array<T>::Array(size_t n): _sizeArr(n), _array(new T[_sizeArr])
template <typename T>
Array<T>::Array(const unsigned int n): _sizeArr(n), _array(new T[_sizeArr])
{
	std::cout << "Array Parameterized Constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(const Array<T> &copyObj): _sizeArr(copyObj._sizeArr), _array(new T[_sizeArr])
{
	std::cout << "Array Copy Constructor called" << std::endl;
	for (size_t i = 0; i < _sizeArr; i++)
		_array[i] = copyObj._array[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &assignCopy)
{
	std::cout << "Array Copy Assignment Operator called" << std::endl;
	if (_sizeArr != assignCopy._sizeArr)
	{
		if (_array)
			delete[] _array;
		_array = new T[assignCopy._sizeArr];
		_sizeArr = assignCopy._sizeArr;
	}
	for (size_t i = 0; i < _sizeArr; i++)
		_array[i] = assignCopy._array[i];
	return (*this);
}

template <typename T>
T &Array<T>::operator[](const size_t index)
{
	if (index >= _sizeArr)
		throw std::out_of_range("Index is out of bounds");
	return (_array[index]);
}

template <typename T>
Array<T>::~Array()
{
	std::cout << "Array Destructor called" << std::endl;
	delete[] _array;
}

template <typename T>
size_t Array<T>::size() const
{
	return (_sizeArr);
}

#endif // ARRAY_TPP