/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:53:18 by asfletch          #+#    #+#             */
/*   Updated: 2024/07/18 17:00:43 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// 0 - 2 work
// 3 and 4 are the same as 1 and 3 but no space
// 3 - 5 dont work

std::string argvCalculate(int arg)
{
	std::string str;
	switch(arg)
	{
		case 0:
			str = "5 3 +";
			break ;
		case 1:
			str = "5 1 2 + 4 * + 3 -";
			break ;
		case 2:
			str = "9 6 3 / * 2 +";
			break ;
		case 3:
			str = "512+4*+3-";
			break ;
		case 4:
			str = "963/*2+";
			break ;
		case 5:
			str = "5 +";
			break ;
		case 6:
			str = "5 3 + a";
			break ;
		case 7:
			str = "2 3 + 4";
			break ;
		default:
			str = "";
			break ;
	}
	return (str);
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
	if (str.empty())
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
