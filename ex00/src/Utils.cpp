/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 15:50:34 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/24 09:52:11 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool checkNanAndRange(double number, const std::string& type)
{
	if (number < std::numeric_limits<int>::min() || number > std::numeric_limits<int>::max())
	{
		std::cout << type << ": out of range" << std::endl;
		std::cout << "-----------------" << std::endl;
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		return (false);
	}
	if (std::isnan(number))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return (false);
	}
	return (true);
}

bool checkIntRange(std::string& toConvert)
{
	long long temp = stoll(toConvert);
	if (temp < std::numeric_limits<int>::min() || temp > std::numeric_limits<int>::max())
	{
		std::cout << "int: out of range" << std::endl;
		std::cout << "char: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return (false);
	}
	return (true);
}

bool checkINF(const std::string& toConvert)
{
	if (toConvert == "nan" || toConvert == "+nan" || toConvert == "-nan")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return (true);
	}
	else if (toConvert == "inf" || toConvert == "+inf" || toConvert == "-inf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << toConvert << "f" << std::endl;
		std::cout << "double: " << toConvert << std::endl;
		return (true);
	}
	return (false);
}
