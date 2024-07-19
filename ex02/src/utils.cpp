/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 11:52:02 by asfletch          #+#    #+#             */
/*   Updated: 2024/07/19 12:37:22 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	PmergeMe::printVector(const std::vector<int>& vec)
{
	std::cout << "After: ";
	for(std::vector<int>::const_iterator iter = vec.begin(); iter != vec.end(); iter++)
		std::cout << *iter << " ";
	std::cout << std::endl;
}

std::vector<int>::iterator PmergeMe::findInsertionPosition(std::vector<int>& sortedVec, int value)
{
	return (std::lower_bound(sortedVec.begin(), sortedVec.end(), value));
}
