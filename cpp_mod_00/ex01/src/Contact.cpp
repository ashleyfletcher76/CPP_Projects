/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 11:22:11 by asfletch          #+#    #+#             */
/*   Updated: 2024/03/26 09:54:34 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact ( void )
{
	return ;
}

Contact::~Contact( void )
{
	return ;
}

void Contact::InputData(int i, const std::string& str)
{
	switch (i)
	{
		case 0:
			_first_name = str; break ;
		case 1:
			_last_name = str; break ;
		case 2:
			_nickname = str; break ;
		case 3:
			_phone_number = str; break ;
		case 4:
			_darkest_secret = str; break ;
	}
}

void Contact::PrintData( void )
{
	std::cout << _first_name << std::endl;
	std::cout << _last_name << std::endl;
	std::cout << _nickname << std::endl;
	std::cout << _phone_number << std::endl;
	std::cout << _darkest_secret << std::endl;
}

std::string	Contact:: GetInfo(int index)
{
	if (index == 0)
		{ return _first_name; }
	if (index == 1)
		{ return _last_name; }
	if (index == 2)
		{ return _nickname; }
	if (index == 3)
		{ return _phone_number; }
	if (index == 4)
		{ return _darkest_secret; }
	return (NULL);
}
