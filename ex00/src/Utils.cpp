/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 15:50:34 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/24 15:29:59 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

double stringConversion(const std::string& toConvert)
{
	if (toConvert == "nan" || toConvert == "NaN")
		return std::numeric_limits<double>::quiet_NaN();
	else if (toConvert == "inf" || toConvert == "+inf" || toConvert == "Inf" || toConvert == "+Inf")
		return std::numeric_limits<double>::infinity();
	else if (toConvert == "-inf" || toConvert == "-Inf")
		return -std::numeric_limits<double>::infinity();
	else if (toConvert == "nanf" || toConvert == "NaNf")
		return std::numeric_limits<float>::quiet_NaN();
	double value;
	std::stringstream ss(toConvert);
	if (!(ss >> value) || !ss.eof())
		throw std::invalid_argument("Invalid argument!");
	return (value);
}

bool hasMultipleDots(const std::string& toConvert)
{
	std::string::size_type	dot = 0;

	for(std::string::size_type i = 0; i < toConvert.length(); i++)
	{
		if (toConvert[i] == '.')
			dot++;
		if (dot > 1)
			return (true);
	}
	return (false);
}

bool checkMaxMinInt(double temp)
{
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

