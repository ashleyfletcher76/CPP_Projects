/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 09:02:44 by asfletch          #+#    #+#             */
/*   Updated: 2024/03/26 11:11:19 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Phonebook.hpp"

void	ManipString(std::string& str, int delim)
{
	if (delim == 1)
	{
		for(std::string::size_type i = 0; i < str.length(); i++)
			str[i] = std::toupper(static_cast<unsigned char>(str[i]));
	}
	size_t start = str.find_first_not_of(' ');
	if (start == std::string::npos)
		str.clear();
	else
	{
		size_t end = str.find_last_not_of(' ');
		str = str.substr(start, end - start + 1);
	}
}

int	MainHelper(std::string& input, Phonebook& phonebook)
{
	ManipString(input, 1);
	if (input == "EXIT")
		return(0);
	else if (input == "ADD")
		phonebook.AddContact();
	else if (input == "SEARCH")
		phonebook.SearchContact();
	else
		std::cout << RED << "Incorrect Input" << RESET << std::endl;
	return (1);
}

int	main(void)
{
	std::string input;
	Phonebook	phonebook;

	while (true)
	{
		std::cin.clear();
		std::cout << GREEN << "Choose Option: ADD, SEARCH or EXIT" << RESET << std::endl;
		std::cout << GREEN << "- " << RESET;
		if (!std::getline(std::cin, input))
		{
			if (std::cin.eof())
			{
				std::cout << std::endl;
				break ;
			}
		}
		else if (MainHelper(input, phonebook) == 0)
			break ;
	}
}
