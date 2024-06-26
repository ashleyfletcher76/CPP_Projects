/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:01:06 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/26 12:20:45 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void	charsString()
{
	std::string	testString1[] = {"Hello", "I am", "A chicken"};
	char		testString2[] = "Hello";
	std::size_t	num1Len = sizeof(testString1) / sizeof(testString1[0]);
	std::size_t	num2Len = sizeof(testString2) - 1;

	std::cout << "Test testString1 squared" << std::endl;
	std::cout << std::endl;
	iter(testString1, num1Len, printString<std::string>);
	std::cout << std::endl;
	std::cout << "------" << std::endl;
	std::cout << "Test testString2 print" << std::endl;
	iter(testString2, num2Len, printString<char>);
	std::cout << std::endl;
}

void	nums()
{
	int	num1[] = {5,6};
	int	num2[] = {5, 6, 7, 8};
	std::size_t	num1Len = sizeof(num1) / sizeof(num1[0]);
	std::size_t	num2Len = sizeof(num2) / sizeof(num2[0] - 1);

	std::cout << "Test num1 squared" << std::endl;
	iter(num1, num1Len, square<int>);
	std::cout << "------" << std::endl;
	std::cout << "Test num2 print" << std::endl;
	iter(num2, num2Len, printInt<int>);
	std::cout << std::endl;
}

int	main()
{
	//nums();
	charsString();
}
