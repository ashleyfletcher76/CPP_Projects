/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:06:15 by asfletch          #+#    #+#             */
/*   Updated: 2024/07/19 11:19:02 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	printVector(const std::vector<int>& vec)
{
	for(std::vector<int>::const_iterator iter = vec.begin(); iter != vec.end(); iter++)
		std::cout << *iter << " ";
	std::cout << std::endl;
}

std::vector<int>::iterator findInsertionPosition(std::vector<int>& sortedVec, int value)
{
	return (std::lower_bound(sortedVec.begin(), sortedVec.end(), value));
}

int	main(int argc, char **argv)
{
	int	numArray[] = {34, 7, 23, 32, 5, 62, 3, 11, 89, 54, 17, 26, 48, 41, 20, 99, 77, 13, 68, 21};
	std::vector<int> nums(numArray, numArray + sizeof(numArray) / sizeof(int));

	(void)argc;
	(void)argv;
	std::vector<std::pair<int, int> > pairs;
	for(std::size_t i = 0; i < nums.size(); i += 2)
	{
		if (i + 1 < nums.size())
		{
			if (nums[i] > nums[i + 1])
				pairs.push_back(std::make_pair(nums[i + 1], nums[i]));
			else
				pairs.push_back(std::make_pair(nums[i], nums[i + 1]));
		}
		else
			pairs.push_back(std::make_pair(nums[i], nums[i]));
	}
	std::vector<int> sortedVec;
	for(std::vector<std::pair<int, int> >::iterator pairIt = pairs.begin(); pairIt != pairs.end(); pairIt++)
	{
		std::vector<int>::iterator pos1 = findInsertionPosition(sortedVec, pairIt->first);
		sortedVec.insert(pos1, pairIt->first);
		std::vector<int>::iterator pos2 = findInsertionPosition(sortedVec, pairIt->second);
		sortedVec.insert(pos2, pairIt->second);
	}
	printVector(sortedVec);
	return (0);
}
