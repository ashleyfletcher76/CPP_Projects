/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 13:03:05 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/06 15:12:38 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() {}

Cure::~Cure() {}

Cure::Cure(const Cure& other) {}

Cure& Cure::operator=(const Cure& other)
{
	if (this != &other)
	{
		(void)other;
	}
	return (*this);
}

Cure::Cure clone()
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std:endl;
}
