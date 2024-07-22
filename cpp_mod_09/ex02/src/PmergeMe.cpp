/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:05:58 by asfletch          #+#    #+#             */
/*   Updated: 2024/07/19 13:22:09 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) : _sortedVec(other._sortedVec),
_vecPairs(other._vecPairs), _vecNums(other._vecNums), _sortedList(other._sortedList),
_listPairs(other._listPairs), _listNums(other._listNums) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		_sortedVec = other._sortedVec;
		_vecPairs = other._vecPairs;
		_vecNums = other._vecNums;
		_sortedList = other._sortedList;
		_listPairs = other._listPairs;
		_listNums = other._listNums;
	}
	return (*this);
}
