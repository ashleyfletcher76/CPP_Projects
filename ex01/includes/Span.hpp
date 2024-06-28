/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:09:55 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/28 13:58:49 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <exception>

class Span
{
	private:
		unsigned int		_maxN;
		std::vector<int>	_nums;

	public:
		Span(unsigned int num);
		~Span();
		Span(const Span& other);
		Span& operator=(const Span& other);

		void			addNumber(int n);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();

		class tooManyValuesException : public std::exception{
			public:
				const char* what() const throw(){
					return ("Vector is full!");}
		};
		class notEnoughValuesException : public std::exception{
			public:
				const char* what() const throw(){
					return ("Vector doesn't have enough!");}
		};
};

Span::Span(unsigned int num) {}

Span::~Span() {}

Span::Span(const Span& other) {}

Span& Span::operator=(const Span& other) {return(*this);}

void	Span::addNumber(int n)
{
	if (_nums.size() > _maxN)
		throw tooManyValuesException();
	_nums.push_back(n);
}

unsigned int	Span::shortestSpan()
{
	if (_nums.size() < 2)
		throw notEnoughValuesException();
	unsigned int minDiff = std::numeric_limits<int>::max();
	std::sort(_nums.begin(), _nums.end());
	for (std::vector<int>::iterator iter = _nums.begin(); iter != _nums.end() - 1; iter++)
	{
		int	diff = *(iter + 1) - *iter;
		if (diff < minDiff)
			diff = minDiff;
	}
	std::cout << "Minimum difference is: " << minDiff << std::endl;
	return (minDiff);
}

unsigned int	Span::longestSpan()
{
	if (_nums.size() < 2)
		throw notEnoughValuesException();
	std::vector<int>::iterator minInt = std::min_element(_nums.begin(), _nums.end());
	unsigned int min = *minInt;
	std::vector<int>::iterator maxInt = std::max_element(_nums.begin(), _nums.end());
	unsigned int max = *minInt;
	unsigned int diff = max - min;
	std::cout << "Largest difference is: " << diff << std::endl;
	return (diff);
}


#endif
