/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 15:50:34 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/24 10:25:07 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool checkMaxMinInt(std::string& toConvert)
{
	long long temp = std::stoll(toConvert);
	if (temp < std::numeric_limits<int>::min() || temp > std::numeric_limits<int>::max())
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		float f = static_cast<float>(temp);
		std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl;
		double d = static_cast<double>(temp);
		std::cout << "double: " << d << std::endl;
		return (true);
	}
	return (false);
}

void	checkArg(std::string& toConvert, double value)
{
	if (std::isnan(value))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (std::isinf(value))
	{
		std::string sign = (value > 0) ? "+" : "-";
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << sign << "inff" << std::endl;
		std::cout << "double: " << sign << "inf" << std::endl;
	}
	else if (toConvert.find('f') != std::string::npos)
		convertFloat(toConvert);
	else
		convertDouble(toConvert);
}
