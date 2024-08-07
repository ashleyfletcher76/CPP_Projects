/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:08:09 by asfletch          #+#    #+#             */
/*   Updated: 2024/07/20 11:19:06 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <string>
#include <cstdlib>
#include <climits>
#include <iomanip>
#include <sstream>

class BitcoinExchange
{
	private:
		// variables
		std::map<std::string, double> _btcPrices;
		std::string _argv;
		std::string	_date;
		float		_amount;
		int			_flag;
		// functions
		int		readDatabase();
		int		readInput();
		void	splitInput(std::string& line);
		int		checkAmount();
		int		checkDate();
		void	calculateExchange(const std::string& date, float rate);

	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);

		void	beginProcess(const std::string& file);
};

#endif
