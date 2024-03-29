/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SearchPhonebook.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:38:42 by asfletch          #+#    #+#             */
/*   Updated: 2024/03/26 11:43:25 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

bool	Phonebook::AskForIndex( void )
{
	std::string input;

	std::cout << YELLOW << "------" << RESET << std::endl;
	std::cout << GREEN << "Choose an index number: " << RESET;
	if (!std::getline(std::cin, input))
	{
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return (false);
		}
	}
	if (!std::cin.good())
	{
		return (false);
	}
	std::cout << YELLOW << "------" << RESET << std::endl;
	ManipString(input, 0);
	int num = atoi(input.c_str());
	if (num > 0 && num <= num_contacts)
		PrintContact(num - 1);
	else
		std::cout << RED << "Input valid index." << RESET << std::endl;
	return (true);
}

void	AddContactHelper(std::string str)
{
	if (str.length() < 10)
		std::cout << RED << std::right << std::setw(10) << std::setfill(' ')
		<< str.substr(0, 9) << RESET << CYAN << "|";
	else
		std::cout << RED << std::right << std::setw(9) << std::setfill(' ')
		<< str.substr(0, 9) << RESET << CYAN << ".|";

}

int	Phonebook::AddContactToPhonebook( void )
{
	for (int i = 0; i < num_contacts; i++)
	{
		std::cout << CYAN << "|" << RESET;
		std::cout << RED << std::right << std::setw(6) << i + 1 << RESET << CYAN << "|";
		AddContactHelper(contacts[i].GetInfo(0));
		AddContactHelper(contacts[i].GetInfo(1));
		AddContactHelper(contacts[i].GetInfo(2));
		std::cout << std::endl;
	}
	std::cout << CYAN << " --------------------------------------- " << RESET << std::endl;
	return (0);
}

int	Phonebook::SearchContact( void )
{
	if (contact_index <= 0)
	{
		std::cout << GREEN << "-----------" << RESET << std::endl;
		std::cout << RED << "No contacts!" << RESET << std::endl;
		std::cout << GREEN << "-----------" << RESET << std::endl;
		return (0);
	}
	else
	{
		std::cout << CYAN << " --------------------------------------- " << RESET << std::endl;
		std::cout << CYAN << "|Index |First Name| Last Name|  Nickname|" << RESET << std::endl;
		std::cout << CYAN << " --------------------------------------- " << RESET << std::endl;
	}
	AddContactToPhonebook();
	if (!AskForIndex())
		return (1);
	return (0);
}
