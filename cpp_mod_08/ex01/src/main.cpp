/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:08:36 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/28 15:48:00 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

//Operator tests
void	checkOperators()
{
	std::cout << "=== COPY OPERATOR TESTS ===" << std::endl;
	Span span(4);
	span.addNumber(5);
	span.addNumber(1);
	span.addNumber(15);
	span.addNumber(12);
	const std::vector<int>& nums = span.getNums();
	for (std::vector<int>::const_iterator iter = nums.begin(); iter != nums.end(); iter++)
		std::cout << *iter << std::endl;

	Span emptySpan(2);
	std::cout << "=== EMPTY CLASS TEST ===" << std::endl;
	const unsigned int max = emptySpan.getMaxN();
	std::cout << max << std::endl;
	const std::vector<int>& nums2 = emptySpan.getNums();
	for (std::vector<int>::const_iterator iter2 = nums2.begin(); iter2 != nums2.end(); iter2++)
		std::cout << *iter2 << std::endl;

	std::cout << "=== AFTER COPY ASIGN TEST ===" << std::endl;
	emptySpan = span;
	const std::vector<int>& nums3 = emptySpan.getNums();
	for (std::vector<int>::const_iterator iter3 = nums3.begin(); iter3 != nums3.end(); iter3++)
		std::cout << *iter3 << std::endl;

	Span copySpan = span;
	emptySpan = span;
	std::cout << "=== AFTER COPY CONSTRUCT TEST ===" << std::endl;
	const std::vector<int>& nums4 = copySpan.getNums();
	for (std::vector<int>::const_iterator iter4 = nums4.begin(); iter4 != nums4.end(); iter4++)
		std::cout << *iter4 << std::endl;
}

//Range tests
void	rangeTest()
{
	std::cout << "=== RANGE TEST 1 ===" << std::endl;
	Span span(10000);
	std::vector<int> vecTest(10000);
	for (unsigned int i = 0; i < 10000; i++)
		vecTest[i] = i;
	try
	{
		span.addNumbers(vecTest.begin(), vecTest.end());
		std::cout << "Range test success" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "=== RANGE TEST 2 ===" << std::endl;
	Span span2(999);
	std::vector<int> vecTest2(99);
	for (unsigned int i = 0; i < 10000; i++)
		vecTest[i] = i;
	try
	{
		span.addNumbers(vecTest2.begin(), vecTest.end());
		std::cout << "Range test success" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

//Vector full test
void	vectorFullTest()
{
	std::cout << "=== VECTOR FULL ===" << std::endl;
	try
	{
		Span span(4);
		span.addNumber(5);
		span.addNumber(1);
		span.addNumber(15);
		span.addNumber(12);
		span.addNumber(7);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

//Correct test
void	correctTest()
{
	std::cout << "=== VECTOR FULL ===" << std::endl;
	try
	{
		Span span(5);
		span.addNumber(5);
		span.addNumber(1);
		span.addNumber(15);
		span.addNumber(12);
		span.addNumber(7);
		span.longestSpan();
		span.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int	main()
{
	vectorFullTest();
	checkOperators();
	rangeTest();
	correctTest();
}
