/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:53:18 by asfletch          #+#    #+#             */
/*   Updated: 2024/07/20 15:09:05 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// 0 - 7 work
// 1 and 2 are the same but no space
// 3 and 4 are the same but no space
// 8 - 10 dont work

std::string argvCalculate(int arg)
{
	std::string str;
	switch(arg)
	{
		case 0:
			str = "5 3 +"; // 8
			break ;
		case 1:
			str = "5 1 2 + 4 * + 3 -"; // 14
			break ;
		case 2:
			str = "512+4*+3-"; // 14
			break ;
		case 3:
			str = "9 6 3 / * 2 +"; // 20
			break ;
		case 4:
			str = "963/*2+"; // 20
			break ;
		case 5:
			str = "3 4 + 2 * 1 5 - 2 3 + / + 6 7 * 5 - 4 + +"; // 55
			break ;
		case 6:
			str = "3 4 + 2 * 7 3 / - 5 +87--"; // 16
			break ;
		case 7:
			str = "5 9 8 + 4 6 * * 7 + 2 - 3 / 3 + 4 * 8 - -"; // -547
			break ;
		case 8:
			str = "5 +";
			break ;
		case 9:
			str = "5 3 + a";
			break ;
		case 10:
			str = "2 3 + 4";
			break ;
		default:
			str = "";
			break ;
	}
	return (str);
}

bool	isNum(const std::string& str)
{
	for(std::size_t i = 0; i < str.length(); i++)
	{
		if (!std::isdigit(str[i]))
			return (false);
	}
	return (true);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Incorrect args" << std::endl;
		return (1);
	}
	int	test = std::atoi(argv[1]);
	std::string str = argvCalculate(test);
	if (!isNum(argv[1]) || test < 0 || test > 10)
	{
		std::cerr << "Invalid test case" << std::endl;
		return (1);
	}
	try
	{
		RPN calculator;
		int	result = calculator.calculate(str);
		std::cout << result << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	if (argc != 2)
// 	{
// 		std::cerr << "Incorrect args" << std::endl;
// 		return (1);
// 	}
// 	if (!isNum(argv[1]))
// 	{
// 		std::cerr << "Invalid test case" << std::endl;
// 		return (1);
// 	}
// 	try
// 	{
// 		RPN calculator;
// 		int	result = calculator.calculate(argv[1]);
// 		std::cout << result << std::endl;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 		return (1);
// 	}
// 	return (0);
// }
