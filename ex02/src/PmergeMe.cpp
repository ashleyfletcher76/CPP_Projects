/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:05:58 by asfletch          #+#    #+#             */
/*   Updated: 2024/07/19 12:38:01 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) : _sortedVec(other._sortedVec),
_pairs(other._pairs), _nums(other._nums) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		_sortedVec = other._sortedVec;
		_pairs = other._pairs;
		_nums = other._nums;
	}
	return (*this);
}

void	PmergeMe::executeVec(const std::string& argv)
{
	std::istringstream iss(argv);
	int	num;
	while (iss >> num)
	{
		if (num < 0)
			throw std::invalid_argument("Error: A negative number has been included.");
		_nums.push_back(num);
	}
	for(std::size_t i = 0; i < _nums.size(); i += 2)
	{
		if (i + 1 < _nums.size())
		{
			if (_nums[i] > _nums[i + 1])
				_pairs.push_back(std::make_pair(_nums[i + 1], _nums[i]));
			else
				_pairs.push_back(std::make_pair(_nums[i], _nums[i + 1]));
		}
		else
			_pairs.push_back(std::make_pair(_nums[i], _nums[i]));
	}
	for(std::vector<std::pair<int, int> >::iterator pairIt = _pairs.begin(); pairIt != _pairs.end(); pairIt++)
	{
		std::vector<int>::iterator pos1 = findInsertionPosition(_sortedVec, pairIt->first);
		_sortedVec.insert(pos1, pairIt->first);
		std::vector<int>::iterator pos2 = findInsertionPosition(_sortedVec, pairIt->second);
		_sortedVec.insert(pos2, pairIt->second);
	}
	std::cout << "Before: " << argv << std::endl;
	printVector(_sortedVec);
}
