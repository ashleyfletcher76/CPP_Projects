/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CheckWhich.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 11:59:29 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/23 12:19:44 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool isChar(const std::string& toConvert)
{
	return (toConvert.length() == 1 && !std::isdigit(toConvert[0]));
}

bool isInt(const std::string& toConvert)
{
	std::istringstream iss(toConvert);
	int	i;
	iss >> i;
	return (!iss.fail() && iss.eof());
}

bool isDouble(const std::string& toConvert)
{
	std::istringstream iss(toConvert);
	double	d;
	iss >> d;
	return(!iss.fail() && iss.eof() && toConvert.find('f') != std::string::npos);
}

bool isFloat(const std::string& toConvert)
{
	std::istringstream iss(toConvert);
	float	f;
	iss >> f;
	return(!iss.fail() && iss.eof() && toConvert.find('f') != std::string::npos);
}
