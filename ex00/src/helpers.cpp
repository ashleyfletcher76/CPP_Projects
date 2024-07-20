/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:58:10 by asfletch          #+#    #+#             */
/*   Updated: 2024/07/20 12:01:02 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void	BitcoinExchange::beginProcess(const std::string& file)
{
	_argv = file;
	if (readDatabase() == 1)
		return ;
	if (readInput() == 1)
		return ;
}

int	BitcoinExchange::checkAmount()
{
	if (_amount < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return (1);
	}
	else if (_amount > static_cast<double>(INT_MAX))
	{
		std::cerr << "Error: too large a number." << std::endl;
		return (1);
	}
	else if (_flag == 1)
	{
		std::cerr << "Error: no amount given." << std::endl;
		return (1);
	}
	return (0);
}

int	BitcoinExchange::checkDate()
{
	std::size_t pos1 = _date.find('-');
	if (pos1 == std::string::npos)
		return (1);
	std::size_t pos2 = _date.find('-', pos1 + 1);
	if (pos2 == std::string::npos)
		return (1);
	std::string year = _date.substr(0, pos1);
	std::string month = _date.substr(pos1 + 1, pos2 - pos1 - 1);
	std::string day = _date.substr(pos2 + 1);
	int y = std::atoi(year.c_str());
	int m = std::atoi(month.c_str());
	int d = std::atoi(day.c_str());
	if (m < 1 || m > 12 || d < 1 || d > 31)
	{
		std::cerr << "Error: bad input => " << _date << std::endl;
		return (1);
	}
	if ((d > 30) && (m == 04 || m == 06 || m == 9 || m == 11))
	{
		std::cerr << "Error: bad input => " << _date << std::endl;
		return (1);
	}
	if (m == 2)
	{
		bool leap = (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
		if (d > 29 || (d == 29 && d != leap))
		{
			std::cerr << "Error: bad input => " << _date << std::endl;
			return (1);
		}
	}
	return (0);
}
