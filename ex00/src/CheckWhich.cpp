/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CheckWhich.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 11:59:29 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/23 15:08:52 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool isChar(const std::string& toConvert)
{
	return (toConvert.length() == 1 && !std::isdigit(toConvert[0]));
}

bool isInt(const std::string& toConvert)
{
	if (toConvert.empty())
		return (false);
	std::istringstream iss(toConvert);
	int	i;
	iss >> i;
	return (!iss.fail() && iss.eof());
}

bool isDouble(const std::string& toConvert)
{
	if (toConvert.empty() || toConvert.find('f') != std::string::npos)
		return(false);
	std::istringstream iss(toConvert);
	double	d;
	iss >> d;
	return(!iss.fail() && iss.eof());
}

bool isFloat(const std::string& toConvert)
{
	if (toConvert.empty() || toConvert.back() != 'f')
		return (false);
	std::istringstream iss(toConvert.substr(0, toConvert.size() - 1));
	float	f;
	iss >> f;
	return(!iss.fail() && iss.eof());
}
