/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:22:20 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/26 15:52:27 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "Array.tpp"

void	stringArray()
{
	
}

void	charArray()
{
	std::cout << "Char array test" << std::endl;
	Array<char> charArray(4);
	//for (size_t i = 0; i < charArray.size(); i++)
	charArray[0] = 'a';
	charArray[1] = 'b';
	charArray[2] = 'c';
	charArray[3] = 'd';
	try
	{
		for (size_t i = 0; i < charArray.size() + 2; i++)
			std::cout << charArray[i] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}

void	intArray()
{
	std::cout << "Int array test" << std::endl;
	Array<int> intArray(5);
	for (size_t i = 0; i < intArray.size(); i++)
		intArray[i] = (i + 1) * 10;
	for (size_t i = 0; i < intArray.size(); i++)
		std::cout << intArray[i] << std::endl;
}

int	main()
{
	intArray();
	std::cout << "--------" << std::endl;
	charArray();
}
