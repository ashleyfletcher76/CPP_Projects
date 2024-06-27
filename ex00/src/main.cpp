/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:17:08 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/27 17:10:13 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main()
{
	std::vector<int> intputVector;
	intputVector.push_back(1);
	intputVector.push_back(2);
	intputVector.push_back(3);
	intputVector.push_back(4);
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
