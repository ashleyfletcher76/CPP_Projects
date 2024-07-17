/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:16:28 by asfletch          #+#    #+#             */
/*   Updated: 2024/07/17 17:19:42 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Invalid argument count" << std::endl;
		return (1);
	}
	BitcoinExchange btc;
	btc.beginProcess(argv[1]);
	return(0);
}
