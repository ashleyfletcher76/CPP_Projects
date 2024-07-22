/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:12:04 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/29 15:02:55 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _maxN(0) {}

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

const std::vector<int>& Span::getNums() const {return (_nums);}

unsigned int Span::getMaxN() const {return (_maxN);}
