/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 11:18:54 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/23 12:08:17 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALERCONVERTER_HPP
# define SCALERCONVERTER_HPP

#include <iostream>
#include <limits>
#include <cctype>
#include <sstream>

class ScalarConverter
{
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);

	public:
		static void convert(std::string& toConvert);
};

// Check which functions
bool isChar(const std::string& toConvert);
bool isInt(const std::string& toConvert);
bool isDouble(const std::string& toConvert);
bool isFloat(const std::string& toConvert);

//Conversion function

#endif
