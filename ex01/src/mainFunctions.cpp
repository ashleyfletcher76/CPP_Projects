/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainFunctions.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:18:24 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/28 15:18:46 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.cpp"

void	Span::addNumber(int n)
{
	if (_nums.size() > _maxN - 1)
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
		unsigned int	diff = *(iter + 1) - *iter;
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
	unsigned int max = *maxInt;
	std::cout << "Largest difference is: " << max - min << std::endl;
	return (max - min);
}
