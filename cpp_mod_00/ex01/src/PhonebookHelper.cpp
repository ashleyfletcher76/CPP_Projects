/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhonebookHelper.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:46:20 by asfletch          #+#    #+#             */
/*   Updated: 2024/03/26 11:32:19 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

void	Phonebook::PrintContact(int index)
{
	if (index < 0)
	{
		std::cout << "Index invalid." << std::endl;
		return ;
	}
	Contact& contact = contacts[index];
	std::cout << MAGENTA << "First name    : " << RESET << contact.GetInfo(0) << std::endl;
	std::cout << MAGENTA << "Last name     : " << RESET << contact.GetInfo(1) << std::endl;
	std::cout << MAGENTA << "Nickname      : " << RESET << contact.GetInfo(2) << std::endl;
	std::cout << MAGENTA << "Phone number  : " << RESET << contact.GetInfo(3) << std::endl;
	std::cout << MAGENTA << "Darkest secret: " << RESET << contact.GetInfo(4) << std::endl;
	std::cout << YELLOW << "------" << RESET << std::endl;
}

bool	IsNumeric(const std::string& str)
{
	if (str.empty()) return (false);
	for(std::string::const_iterator iter = str.begin(); iter != str.end(); ++iter)
		if (!isdigit(static_cast<unsigned char>(*iter))) return false;
	return (true);
}

bool	OnlySpace(const std::string& str)
{
	return (str.find_first_not_of(" \t\r\n\f\v") == std::string::npos);
}
