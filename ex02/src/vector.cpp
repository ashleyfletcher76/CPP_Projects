/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 11:52:02 by asfletch          #+#    #+#             */
/*   Updated: 2024/07/19 15:57:34 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	PmergeMe::executeVec(const std::string& argv)
{
	std::istringstream iss(argv);
	int	num;
	while (iss >> num)
	{
		if (num < 0)
			throw std::invalid_argument("Error: A negative number has been included.");
		_vecNums.push_back(num);
	}
	_vecPairs.reserve(_vecNums.size() / 2 + 1);
	for(std::size_t i = 0; i < _vecNums.size(); i += 2)
	{
		if (i + 1 < _vecNums.size())
		{
			if (_vecNums[i] > _vecNums[i + 1])
				_vecPairs.push_back(std::make_pair(_vecNums[i + 1], _vecNums[i]));
			else
				_vecPairs.push_back(std::make_pair(_vecNums[i], _vecNums[i + 1]));
		}
		else
			_vecPairs.push_back(std::make_pair(_vecNums[i], _vecNums[i]));
	}
	_sortedVec.reserve(_vecNums.size());
	for(std::vector<std::pair<int, int> >::iterator pairIt = _vecPairs.begin(); pairIt != _vecPairs.end(); pairIt++)
	{
		std::vector<int>::iterator pos1 = findInsertionPosition(_sortedVec, pairIt->first);
		if (pos1 == _sortedVec.end() || *pos1 != pairIt->first)
			_sortedVec.insert(pos1, pairIt->first);
		std::vector<int>::iterator pos2 = findInsertionPosition(_sortedVec, pairIt->second);
		if (pos2 == _sortedVec.end() || *pos2 != pairIt->second)
			_sortedVec.insert(pos2, pairIt->second);
	}
	// printBegin(argv);
	printVector(_sortedVec);
}

void	PmergeMe::printVector(const std::vector<int>& vec) const
{
	std::cout << "After vec: ";
	std::size_t count = 0;
	for(std::vector<int>::const_iterator iter = vec.begin(); iter != vec.end(); iter++)
	{
		if (count >= 6)
		{
			std::cout << "...";
			break ;
		}
		std::cout << *iter << " ";
		count++;
	}
	std::cout << std::endl;
}

std::vector<int>::iterator PmergeMe::findInsertionPosition(std::vector<int>& sortedVec, int value)
{
	return (std::lower_bound(sortedVec.begin(), sortedVec.end(), value));
}
