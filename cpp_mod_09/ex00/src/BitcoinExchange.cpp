/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:11:17 by asfletch          #+#    #+#             */
/*   Updated: 2024/07/20 12:00:08 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _btcPrices(other._btcPrices), _argv(other._argv),
_date(other._date), _amount(other._amount), _flag(other._flag) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		_btcPrices = other._btcPrices;
		_argv = other._argv;
		_date = other._date;
		_amount = other._amount;
		_flag = other._flag;
	}
	return(*this);
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
			_btcPrices[date] = price; // stores date and corresponding value together
		}
	}
	database.close();
	return (0);
}

int	BitcoinExchange::readInput()
{
	std::string line;
	std::ifstream input(_argv.c_str()); // input file stream
	if (!input)
	{
		std::cerr << "Could not open input file." << std::endl;
		return (1);
	}
	while(std::getline(input, line))
	{
		_amount = 0;
		_flag = 0;
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
		_date.erase(0, _date.find_first_not_of("\n\r\t"));
		std::string value = line.substr(pos + 1);
		_amount = std::strtof(value.c_str(), NULL);
	}
	else
	{
		_date = line.substr(0, pos - 1);
		_date.erase(_date.find_last_not_of("\n\r\t") + 1);
		_date.erase(0, _date.find_first_not_of("\n\r\t"));
		_flag = 1;
	}
}

void	BitcoinExchange::calculateExchange(const std::string& date, float rate)
{
	float	exchange = _amount * rate;
	std::ostringstream oss;
	if (exchange == static_cast<int>(exchange))
		oss << std::fixed << std::setprecision(0) << exchange; // set value with no decimal points
	else
	{
		oss << std::fixed << std::setprecision(2) << exchange; // set to two
		std::string exchangeStr = oss.str();
		exchangeStr.erase(exchangeStr.find_last_not_of('0') + 1, std::string::npos);
		if (exchangeStr[exchangeStr.size() - 1] == '.')
			exchangeStr.erase(exchangeStr.size() - 1); // removes last decimal if there is one
		oss.str("");
		oss << exchangeStr;
	}
	std::cout << date << " => " << _amount << " = " << oss.str() << std::endl;
}
