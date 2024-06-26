/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:07:32 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/26 15:42:56 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

#include "Array.hpp"

template<typename T>
Array<T>::Array() : elements(NULL), _arraySize(0) {}

template<typename T>
Array<T>::Array(unsigned int n) : elements(new T[n]()), _arraySize(n) {}

template<typename T>
Array<T>::~Array()	{delete[] elements;}

template<typename T>
Array<T>::Array(const Array& other) : elements(new T[other.arraySize]), _arraySize(other._arraySize)
{
	for (size_t i = 0; i < other._arraySize; i++)
		elements[i] = other.elements[i];
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if (this != &other)
	{
		delete[] elements;
		_arraySize = other._arraySize;
		elements = new T[_arraySize];
		for (size_t i = 0; i < other._arraySize; i++)
			elements[i] = other.elements[i];
	}
	return (*this);
}

template<typename T>
T& Array<T>::operator[](int i)
{
	if (i < 0 || static_cast<size_t>(i) >= _arraySize)
		throw OutOfBoundsException();
	return (elements[i]);
}

template<typename T>
size_t Array<T>::size() const
{
	return (_arraySize);
}

#endif
