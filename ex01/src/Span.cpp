/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:12:04 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/28 15:20:42 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int num) : _maxN(num) {}

Span::~Span() {}

Span::Span(const Span& other) : _maxN(other._maxN), _nums(other._nums) {}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_nums = other._nums;
		_maxN = other._maxN;
	}
	return(*this);
}

template<typename inputIterator>
void	addNumbers(inputIterator begin, inputIterator end)
{
	for(inputIterator iter = begin; iter != end; iter++)
		addNumber(*iter);
}

const std::vector<int>& Span::getNums() const {return (_nums);}

const unsigned int Span::getMaxN() const {return (_maxN);}
