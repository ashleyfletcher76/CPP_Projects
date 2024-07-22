/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CheckWhich.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 11:59:29 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/24 14:52:06 by asfletch         ###   ########.fr       */
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
	long long	i;
	iss >> i;
	return (!iss.fail() && iss.eof()
		&& i >= std::numeric_limits<int>::min() && i <= std::numeric_limits<int>::max());
}

bool isDouble(const std::string& toConvert)
{
	if (toConvert.empty() || toConvert.find('f') != std::string::npos)
		return(false);
	if (toConvert == "inf" || toConvert == "+inf" || toConvert == "-inf" || toConvert == "nan")
		return (true);
	std::istringstream iss(toConvert);
	double	d;
	iss >> d;
	return(!iss.fail() && iss.eof());
}

bool isFloat(const std::string& toConvert)
{
	if (toConvert.empty() || toConvert[toConvert.size() - 1] != 'f')
		return (false);
	if (toConvert == "inf" || toConvert == "+inf" || toConvert == "-inf" || toConvert == "nan")
		return (true);
	std::istringstream iss(toConvert.substr(0, toConvert.size() - 1));
	float	f;
	iss >> f;
	return(!iss.fail() && iss.eof());
}
