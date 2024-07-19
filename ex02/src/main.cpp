/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:06:15 by asfletch          #+#    #+#             */
/*   Updated: 2024/07/19 12:43:57 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

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
		clock_t start = clock();
		PmergeMe sorter;
		sorter.executeVec(oss.str());
		clock_t end = clock();
		double duration = double(end - start) / CLOCKS_PER_SEC * 1e6;
		std::cout << "Time to process a range of " << argc - 1
			<< " elements with std::vector : " << duration << " us" <<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
