/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConversionFunctions.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 11:36:20 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/24 09:53:35 by asfletch         ###   ########.fr       */
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
		if (!checkIntRange(toConvert))
			return ;
		int	i = std::stoi(toConvert);
		if (i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max() || !std::isprint(i))
			std::cout << "char: Non displayable." << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
		std::cout << "int: " << i << std::endl;
		float	f = static_cast<float>(i);
		std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl;
		double	d = static_cast<double>(i);
		std::cout << "double: " << d << std::endl;
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
		if (!checkNanAndRange(d, "double"))
			return ;
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
		if (!checkNanAndRange(f, "float"))
			return ;
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

