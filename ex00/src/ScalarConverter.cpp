/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 11:19:27 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/24 09:53:00 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter&) {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) {return (*this);}

void ScalarConverter::convert(std::string toConvert)
{
	if (checkINF(toConvert))
		return ;
	if (isChar(toConvert))
		convertChar(toConvert);
	else if (isInt(toConvert))
		convertInt(toConvert);
	else if (isDouble(toConvert))
		convertDouble(toConvert);
	else if (isFloat(toConvert))
		convertFloat(toConvert);
	else
		std::cout << "Not a valid argument." << std::endl;
}
