/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConversionFunctions.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 11:36:20 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/23 15:46:24 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void	convertChar(std::string& toConvert)
{
	char c = toConvert[0];
	if (std::isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Not displayable." << std::endl;
	int	i = static_cast<int>(c);
		std::cout << "int: " << i << std::endl;
	float	f = static_cast<float>(c);
		std::cout << "float: " << f << ".0f" << std::endl;
	double	d = static_cast<double>(c);
		std::cout << "double: " << d << ".0" << std::endl;
}
void	convertInt(std::string& toConvert)
{
	try
	{
		long long temp = stoll(toConvert);
		if (temp < std::numeric_limits<int>::min() || temp > std::numeric_limits<int>::max())
		{
			std::cout << "int: out of range" << std::endl;
			std::cout << "char: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			return ;
		}
		int	i = std::stoi(toConvert);
		if (i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max() || !std::isprint(i))
			std::cout << "char: Non displayable." << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
		std::cout << "int: " << i << std::endl;
		float	f = static_cast<float>(i);
		std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl;
		double	d = static_cast<double>(i);
		std::cout << "double: " << d << ".0" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Conversion to int failed: " << e.what() << '\n';
	}
}

void	convertDouble(std::string& toConvert)
{
	try
	{
		double	d = std::stod(toConvert);
		if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
		{
			std::cout << "double: out of range" << std::endl;
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			return ;
		}
		 if (std::isnan(d))
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: nanf" << std::endl;
			std::cout << "double: nan" << std::endl;
			return ;
		}
		if (d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max()
			|| !std::isprint(static_cast<int>(d)))
			std::cout << "char: Non displayable." << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
		int	i = static_cast<int>(d);
		std::cout << "int: " << i << std::endl;
		float	f = static_cast<float>(d);
		std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Conversion to double failed: " << e.what() << '\n';
	}
}

void	convertFloat(std::string& toConvert)
{
	try
	{
		float f = std::stof(toConvert);
		if (f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max())
		{
			std::cout << "float: out of range" << std::endl;
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			return ;
		}
		if (std::isnan(f))
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: nanf" << std::endl;
			std::cout << "double: nan" << std::endl;
			return ;
		}
		if (f < std::numeric_limits<char>::min() || f > std::numeric_limits<char>::max()
			|| !std::isprint(static_cast<int>(f)))
			std::cout << "char: Non displayable." << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
		int	i = static_cast<int>(f);
		std::cout << "int: " << i << std::endl;
		std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl;
		double	d = static_cast<double>(f);
		std::cout << "double: " << d << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Conversion to float failed: " << e.what() << '\n';
	}
}

