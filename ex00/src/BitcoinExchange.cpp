/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:11:17 by asfletch          #+#    #+#             */
/*   Updated: 2024/07/18 09:55:31 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _btcPrices(other._btcPrices), _argv(other._argv),
_date(other._date), _amount(other._amount) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		_btcPrices = other._btcPrices;
		_argv = other._argv;
		_date = other._date;
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
		_amount = 0;
		splitInput(line);
		if (checkDate() == 1)
			continue ;
		if (checkAmount() == 1)
			continue ;
		std::map<std::string, double>::iterator iter = _btcPrices.find(_date);
		if (iter != _btcPrices.end())
			calculateExchange(_date, iter->second);
		else
		{
			std::string& originDate = _date;
			iter = _btcPrices.lower_bound(_date);
			if (iter == _btcPrices.begin())
				std::cout << "No date available." << std::endl;
			else
			{
				--iter;
				calculateExchange(originDate, iter->second);
			}
		}
	}
	return (0);
}

void	BitcoinExchange::splitInput(std::string& line)
{
	std::size_t pos = line.find('|');
	if (pos != std::string::npos)
	{
		_date = line.substr(0, pos - 1);
		_date.erase(_date.find_last_not_of("\n\r\t") + 1);
		std::string value = line.substr(pos + 1);
		_amount = std::strtof(value.c_str(), NULL);
		// std::cout << "Parsed Date: " << _date << ", Parsed Amount: " << _amount << std::endl;
	}
	else
	{
		_date = line.substr(0, pos - 1);
		_date.erase(_date.find_last_not_of("\n\r\t") + 1);
	}
}

int	BitcoinExchange::checkAmount()
{
	if (_amount < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return (1);
	}
	else if (_amount > INT_MAX)
	{
		std::cerr << "Error: too large a number." << std::endl;
		return (1);
	}
	return (0);
}

int	BitcoinExchange::checkDate()
{
	std::size_t pos1 = _date.find('-');
	if (pos1 == std::string::npos) return (1);
	std::size_t pos2 = _date.find('-', pos1 + 1);
	if (pos2 == std::string::npos) return (1);
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
		if (d > 29 || (d == 29 != leap))
		{
			std::cerr << "Error: bad input => " << _date << std::endl;
			return (1);
		}
	}
	return (0);
}

void	BitcoinExchange::calculateExchange(const std::string& date, float rate)
{
	float	exchange = _amount * rate;
	std::cout << date << " => " << _amount << " = " << exchange << std::endl;
}
