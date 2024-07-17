/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:11:17 by asfletch          #+#    #+#             */
/*   Updated: 2024/07/17 18:35:13 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _btcPrices(other._btcPrices), _argv(other._argv),
_amount(other._amount) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		_btcPrices = other._btcPrices;
		_argv = other._argv;
		_amount = other._amount;
	}
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
	std::ifstream input(_argv.c_str());
	if (!input)
	{
		std::cerr << "Could not open input file." << std::endl;
		return (1);
	}
	while(std::getline(input, line))
	{
		takeAmount(line);
		std::map<std::string, double>::iterator iter = _btcPrices.find(_date);
		if (iter != _btcPrices.end())
		{
			calculateExchange(_date, iter->second);
		}
		else
		{
			iter = _btcPrices.lower_bound(_date);
			if (iter == _btcPrices.begin())
				std::cout << "No date available." << std::endl;
			else
			{
				--iter;
				calculateExchange(iter->first, iter->second);
			}
		}
	}
	return (0);
}

void	BitcoinExchange::takeAmount(std::string& line)
{
	std::size_t pos = line.find('|');
	if (pos != std::string::npos)
	{
		_date = line.substr(0, pos - 1);
		_date.erase(_date.find_last_not_of("\n\r\t") + 1);
		//std::cout << "Date: " << _date << "." << std::endl;
		std::string value = line.substr(pos + 1);
		_amount = std::strtof(value.c_str(), NULL);
		//std::cout << "Amount: " << _amount << "." << std::endl;
	}
}

void	BitcoinExchange::calculateExchange(const std::string& date, float rate)
{
	float	exchange = _amount * rate;
	std::cout << date << " => " << _amount << " = " << exchange << std::endl;
}
