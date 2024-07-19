/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:59:21 by asfletch          #+#    #+#             */
/*   Updated: 2024/07/19 15:28:36 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	PmergeMe::executeList(const std::string& argv)
{
	std::istringstream iss(argv);
	int	num;
	while (iss >> num)
	{
		if (num < 0)
			throw std::invalid_argument("Error: A negative number has been included.");
		_listNums.push_back(num);
	}
	std::list<int>::iterator iter = _listNums.begin();
	while(iter != _listNums.end())
	{
		std::list<int>::iterator nextIt = iter;
		nextIt++;
		if (nextIt != _listNums.end())
		{
			if (*iter > *nextIt)
				_listPairs.push_back(std::make_pair(*nextIt, *iter));
			else
				_listPairs.push_back(std::make_pair(*iter, *nextIt));
			iter++;
		}
		else
			_listPairs.push_back(std::make_pair(*iter, *iter));
		iter++;
	}
	for(std::list<std::pair<int, int> >::iterator pairIt = _listPairs.begin(); pairIt != _listPairs.end(); pairIt++)
	{
		std::list<int>::iterator pos1 = findInsertionPosition(_sortedList, pairIt->first);
		if (pos1 == _sortedList.end() || *pos1 != pairIt->first)
			_sortedList.insert(pos1, pairIt->first);
		std::list<int>::iterator pos2 = findInsertionPosition(_sortedList, pairIt->second);
		if (pos2 == _sortedList.end() || *pos2 != pairIt->second)
			_sortedList.insert(pos2, pairIt->second);
	}
	// printBegin(argv);
	printList(_sortedList);
}

std::list<int>::iterator PmergeMe::findInsertionPosition(std::list<int>& sortedList, int value)
{
	for(std::list<int>::iterator iter = sortedList.begin(); iter != sortedList.end(); iter++)
	{
		if (*iter >= value)
			return (iter);
	}
	return (sortedList.end());
}

void	PmergeMe::printList(const std::list<int>& list) const
{
	std::cout << "After list: ";
	std::size_t count = 0;
	for (std::list<int>::const_iterator iter = list.begin(); iter != list.end(); iter++)
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
