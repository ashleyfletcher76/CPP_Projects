/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:16:28 by asfletch          #+#    #+#             */
/*   Updated: 2024/07/18 10:47:12 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void	testSwitch(int num)
{
	BitcoinExchange btc;
	switch(num)
	{
		case 0:
			btc.beginProcess("schoolExample.txt");
			break ;
		case 1:
			btc.beginProcess("edgeCases.txt");
			break ;
		case 2:
			btc.beginProcess("random.txt");
			break ;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Invalid argument count" << std::endl;
		return (1);
	}
	int test = std::atoi(argv[1]);
	testSwitch(test);
	return(0);
}
