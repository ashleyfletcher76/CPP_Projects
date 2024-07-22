/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 11:18:54 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/24 15:25:58 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALERCONVERTER_HPP
# define SCALERCONVERTER_HPP

#include <iostream>
#include <limits>
#include <cctype>
#include <sstream>
#include <cmath>
#include <iomanip>
#include <string>

class ScalarConverter
{
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter&);
		ScalarConverter& operator=(const ScalarConverter&);

	public:
		static void convert(std::string toConvert);
};

// Check which functions
bool	isChar(const std::string& toConvert);
bool	isInt(const std::string& toConvert);
bool	isDouble(const std::string& toConvert);
bool	isFloat(const std::string& toConvert);

//Conversion function
void	convertChar(std::string& toConvert);
void	convertInt(std::string& toConvert);
void	convertDouble(std::string& toConvert);
void	convertFloat(std::string& toConvert);

//utils
bool	checkMaxMinInt(double temp);
void	checkArg(std::string& toConvert, double value);
bool	hasMultipleDots(const std::string& toConvert);
double	stringConversion(const std::string& toConvert);

#endif
