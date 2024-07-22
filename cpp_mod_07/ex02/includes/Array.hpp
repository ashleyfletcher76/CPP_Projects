/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:22:50 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/26 15:42:39 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <exception>
#include <cstdlib>

template<typename T>
class Array
{
	private:
		T*		elements;
		size_t	_arraySize;

	public:
		Array();
		Array(unsigned int n);
		~Array();
		Array(const Array& other);
		Array& operator=(const Array& other);

		T& operator[](int i);
		size_t	size() const;

		class OutOfBoundsException : public std::exception
		{
			public:
				const char* what() const throw(){
					return ("Out of bounds!");}
		};
};

#endif
