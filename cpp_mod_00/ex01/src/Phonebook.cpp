/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 11:32:12 by asfletch          #+#    #+#             */
/*   Updated: 2024/03/26 11:23:00 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook( void )
{
	contact_index = 0;
	num_contacts = 0;
}

Phonebook::~Phonebook( void )
{
	std::cout << CYAN <<"Program ending.." << RESET <<std::endl;
}

bool	ValidName(std::string& input, const std::string& name)
{
	do
	{
		std::cout << MAGENTA << "Enter " << name << RESET;
		if (!std::getline(std::cin, input))
		{
			if (std::cin.eof())
			{
				std::cout << std::endl;
				return (false);
			}
		}
		if (!IsNumeric(input) && !input.empty() && input.length() <= 30 && !OnlySpace(input))
			return (true) ;
		else
		{
			std::cout << RED << "---------" << RESET << std::endl;
			std::cout << CYAN << "Enter a valid name." << RESET << std::endl;
			std::cout << RED << "---------" << RESET << std::endl;
		}
	} while (true);
}

bool	ValidPhoneNumber(std::string& input)
{
	do
	{
		std::cout << MAGENTA << "Enter phone number: " << RESET;
		if (!std::getline(std::cin, input))
		{
			if (std::cin.eof())
			{
				std::cout << std::endl;
				return (false);
			}
		}
		if (IsNumeric(input))
		{
			return (true);
		}
		else
		{
			std::cout << RED << "---------" << RESET << std::endl;
			std::cout << CYAN << "Enter a valid number." << RESET << std::endl;
			std::cout << RED << "---------" << RESET << std::endl;
		}
	} while (true);
}

bool	AddContactHelper(std::string& input, int i)
{
	switch(i)
	{
		case 0:	return ValidName(input, "first name: ");
		case 1: return ValidName(input, "last name: ");
		case 2: return ValidName(input, "nickname: ");
		case 3: return ValidPhoneNumber(input);
		case 4: return ValidName(input, "your darkest secret: ");
	}
	return (false);
}

int	Phonebook::AddContact( void )
{
	int	i = 0;
	std::string	input;
	Contact 	contact;

	if (contact_index >= 8)
		contact_index = 0;
	while (i < 5)
	{
		if (!AddContactHelper(input, i))
			return (1);
		if (!std::cin.good())
			return (1);
		contact.InputData(i, input);
		i++;
	}
	if (num_contacts < 8)
		num_contacts++;
	contacts[contact_index++] = contact;
	return (0);
}
