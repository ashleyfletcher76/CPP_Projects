/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:11:14 by asfletch          #+#    #+#             */
/*   Updated: 2024/03/29 08:23:17 by asfletch         ###   ########.fr       */
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

void Harl::complain(std::string level)
{
	std::string levels[NUM_LEVELS] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for(int i = 0; i < NUM_LEVELS; i++)
	{
		if (level == levels[i])
			return (this->*actions[i])();
	}
}

int	main( void )
{
	Harl harl;

	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
}
