/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:06:15 by asfletch          #+#    #+#             */
/*   Updated: 2024/07/19 15:57:39 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	PmergeMe::printBegin(const std::string& argv) const
{
	std::cout << "Before: ";
	std::istringstream iss(argv);
	int num;
	std::size_t count = 0;
	while (iss >> num)
	{
		if (count >= 5)
		{
			std::cout << "...";
			break ;
		}
		if (count > 0)
			std::cout << " ";
		std::cout << num;
		++count;
	}
	std::cout << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Error: Not a valid argument count." << std::endl;
		return (1);
	}
	try
	{
		std::ostringstream oss;
		for(int i = 1; i < argc; i++)
		{
			if (i > 1)
				oss << " ";
			oss << argv[i];
		}
		std::string input = oss.str()
;		clock_t startVec = clock();
		PmergeMe _sorterVec;
		_sorterVec.printBegin(input);
		_sorterVec.executeVec(input);
		clock_t endVec = clock();
		double durationVec = double(endVec - startVec) / CLOCKS_PER_SEC * 1e6;
		std::cout << "Time to process a range of " << argc - 1
			<< " elements with std::vector : " << durationVec << " us" <<std::endl;
		clock_t startList = clock();
		PmergeMe sorterList;
		sorterList.executeList(input);
		clock_t endList = clock();
		double durationList = double(endList - startList) / CLOCKS_PER_SEC * 1e6;
		std::cout << "Time to process a range of " << argc - 1
			<< " elements with std::list : " << durationList << " us" <<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
