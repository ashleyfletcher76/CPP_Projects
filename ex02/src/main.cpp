/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:06:15 by asfletch          #+#    #+#             */
/*   Updated: 2024/07/19 12:30:14 by asfletch         ###   ########.fr       */
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
		PmergeMe sorter;
		sorter.executeVec(oss.str());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
