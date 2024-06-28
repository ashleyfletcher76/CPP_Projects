/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:17:08 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/28 09:26:36 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

void	foundTests()
{
	std::vector<int> intputVector;
	for (std::size_t i = 0; i < 5; i++)
		intputVector.push_back(i + 1);
	std::cout << "==== TEST 1 ====" << std::endl;
	try
	{
		std::vector<int>::iterator it = easyfind(intputVector, 3);
		std::cout << "Number found: " << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	notFoundTests()
{
	std::vector<int> intputVector;
	for (std::size_t i = 0; i < 5; i++)
		intputVector.push_back(i + 1);
	std::cout << "==== TEST 2 ====" << std::endl;
	try
	{
		std::vector<int>::iterator it = easyfind(intputVector, 12);
		std::cout << "Number found: " << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int	main()
{
	foundTests();
	notFoundTests();

}
