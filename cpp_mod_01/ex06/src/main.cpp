/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 07:20:50 by asfletch          #+#    #+#             */
/*   Updated: 2024/03/29 08:39:40 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

enum Level {DEBUG, INFO, WARNING, ERROR, NUM_LEVELS};

Harl::Harl()
{
	actions[DEBUG] = &Harl::debug;
	actions[INFO] = &Harl::info;
	actions[WARNING] = &Harl::warning;
	actions[ERROR] = &Harl::error;
}

void Harl::complain(int index)
{
	for (int i = 0; i < NUM_LEVELS; i++)
	{
		if (i >= index)
		{
			switch(i)
			{
				case DEBUG:
					(this->*actions[DEBUG])();
					break ;
				case INFO:
					(this->*actions[INFO])();
					break ;
				case WARNING:
					(this->*actions[WARNING])();
					break ;
				case ERROR:
					(this->*actions[ERROR])();
					break ;
				default:
					std::cerr << "Invalid level." << std::endl;
			}
		}
	}
}

int Harl::CheckArg(std::string arg, std::string* levels)
{
	for (int i = 0; i < NUM_LEVELS; i++)
	{
		if (arg == levels[i])
			return (i);
	}
	return (-1);
}

int	main(int argc, char **argv)
{
	Harl harl;

	if (argc != 2)
	{
		std::cerr << "Incorrect argument count." << std::endl;
		return (2);
	}
	std::string levels[NUM_LEVELS] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int index = harl.CheckArg(argv[1], levels);
	if (index == -1)
	{
		std::cerr << "Incorrect argument." << std::endl;
		return (2);
	}
	harl.complain(index);
}
