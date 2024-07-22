/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:06:15 by asfletch          #+#    #+#             */
/*   Updated: 2024/07/20 15:12:02 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


bool isNumber(const std::string& str)
{
	for (std::string::const_iterator iter = str.begin(); iter != str.end(); iter++)
	{
		if (!std::isdigit(*iter))
			return (false);
	}
	return (true);
}

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

void	beginList(int argc, char **argv)
{
	clock_t startList = clock();
	std::ostringstream oss;
	for(int i = 1; i < argc; i++)
	{
		if (i > 1)
			oss << " ";
		oss << argv[i];
	}
	PmergeMe sorterList;
	std::string input = oss.str();
	sorterList.executeList(input);
	clock_t endList = clock();
	double durationList = double(endList - startList) / CLOCKS_PER_SEC * 1e6;
	std::cout << "Time to process a range of " << argc - 1
		<< " elements with std::list : " << durationList << " us" <<std::endl;
}

void	beginVec(int argc, char **argv)
{
	clock_t startVec = clock();
	std::ostringstream oss;
	for(int i = 1; i < argc; i++)
	{
		if (i > 1)
			oss << " ";
		oss << argv[i];
	}
	std::string input = oss.str();
	PmergeMe _sorterVec;
	_sorterVec.printBegin(input);
	_sorterVec.executeVec(input);
	clock_t endVec = clock();
	double durationVec = double(endVec - startVec) / CLOCKS_PER_SEC * 1e6;
	std::cout << "Time to process a range of " << argc - 1
		<< " elements with std::vector : " << durationVec << " us" <<std::endl;
}

int	main(int argc, char **argv)
{
	if (argc < 2 || argc > 3001)
	{
		std::cout << "Error: Not a valid argument count." << std::endl;
		return (1);
	}
	for (int i = 1; i < argc; ++i)
	{
		std::string arg = argv[i];
		arg.erase(0, arg.find_first_not_of(' '));
		arg.erase(arg.find_last_not_of(' ') + 1);
		if (!isNumber(arg)) {
			std::cout << "Error: invalid input. All arguments must be positive integers." << std::endl;
			return (1);
		}
	}
	try
	{
		beginVec(argc, argv);
		beginList(argc, argv);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}

// Valid test cases
// ./PmergeMe 1 5 3 9 7 2 8 4 6 10
// ./PmergeMe 2 4 6 8 10 12 14 16 18 20
// ./PmergeMe 100 99 98 97 96 95 94 93 92 91
// ./PmergeMe 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1
// ./PmergeMe 1 1 1 1 1 1 1 1 1 1
// ./PmergeMe 10 9 8 7 6 5 4 3 2 1
// ./PmergeMe 1000 999 998 997 996 995 994 993 992 991
// ./PmergeMe 1 2 3 4 5 6 7 8 9 10
// ./PmergeMe `jot -b 1000 3000 | tr "\n" " "`
// ./PmergeMe `jot -r 3000 3000 1 | tr "\n" " "`


// Invalid test cases
// ./PmergeMe 10 9 8 -7 6 5 4 3 2 1  # Contains a negative number
// ./PmergeMe 1 2 3 4 five 6 7 8 9 10  # Contains a non-integer value
