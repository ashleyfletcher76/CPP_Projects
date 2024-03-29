/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 09:39:36 by asfletch          #+#    #+#             */
/*   Updated: 2024/03/26 09:54:09 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>
#include <string>

class Contact
{
	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _phone_number;
		std::string _darkest_secret;

	public:
		void InputData(int i, const std::string& str);
		void PrintData( void );
		Contact( void );
		~Contact( void );
		std::string GetInfo(int index);
		// std::string GetFirstName() const { return _first_name; }
		// std::string GetLastName() const { return _last_name; }
		// std::string GetNickname() const { return _nickname; }
		// std::string GetPhoneNumber() const { return _phone_number; }
		// std::string GetDarkestSecret() const { return _darkest_secret; }
};

#endif
