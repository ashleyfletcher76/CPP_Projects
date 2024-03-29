/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 09:39:39 by asfletch          #+#    #+#             */
/*   Updated: 2024/03/26 11:22:43 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H

#include <string>
#include <iostream>
#include <cctype>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include "Contact.hpp"

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

bool	IsNumeric(const std::string& str);
void	ManipString(std::string& str, int delim);
bool	OnlySpace(const std::string& str);

class Phonebook
{
	private:
		Contact	contacts[8];
		int	contact_index;
		int	num_contacts;

	public:
		Phonebook( void );
		~Phonebook( void );
		void PrintContact(int index);
		int	AddContact ( void );
		int	SearchContact ( void );
		int	AddContactToPhonebook( void );
		bool AskForIndex( void );
};

#endif
