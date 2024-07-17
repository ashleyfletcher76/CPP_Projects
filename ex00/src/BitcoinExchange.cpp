/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:11:17 by asfletch          #+#    #+#             */
/*   Updated: 2024/07/17 17:30:14 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _argv(NULL) {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _btcPrices(other._btcPrices) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		_btcPrices = other._btcPrices;
	return(*this);
}

void	BitcoinExchange::beginProcess(const std::string& file)
{
	_argv = file;
	if (readDatabase() == 1)
		return ;
	if (readInput() == 1)
		return ;
}

int	BitcoinExchange::readDatabase()
{
	std::ifstream database("data.csv");
	if (!database)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}
	std::string line;

	while(std::getline(database, line))
	{
		std::string date;
		double price;
		std::size_t pos = line.find(',');
		if (pos != std::string::npos)
		{
			date = line.substr(0, pos);
			price = std::strtod(line.substr(pos + 1).c_str(), NULL);
			_btcPrices[date] = price;
		}
	}
	database.close();
	return (0);
}

int	BitcoinExchange::readInput()
{
	std::string line;
	std::ifstream input(_argv);
	if (!input)
	{
		std::cerr << "Could not open input file." << std::endl;
		return (1);
	}
	while(std::getline(input, line))
	{
		std::map<std::string, double>::iterator iter = _btcPrices.find(line);
		if (iter != _btcPrices.end())
			std::cout << line << " = " << iter->second << std::endl;
		else
		{
			iter = _btcPrices.lower_bound(line);
			if (iter == _btcPrices.begin())
				std::cout << "No date available." << std::endl;
			else
			{
				--iter;
				std::cout << "Closest price on " << iter->first << " is " << iter->second << std::endl;
			}
		}
	}
	return (0);
}
