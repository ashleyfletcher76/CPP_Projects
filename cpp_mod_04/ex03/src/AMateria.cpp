/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:09:50 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/07 13:49:28 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("") {}

AMateria::~AMateria() {}

AMateria::AMateria(const AMateria& other) : _type(other._type) {}

AMateria& AMateria::operator=(const AMateria& other)
{
	if (this != &other)
	{
		_type = other._type;
	}
	return (*this);
}

AMateria::AMateria(std::string const& type) : _type(type) {}

std::string const& AMateria::getType() const
{
	return (_type);
}

AMateria* AMateria::clone() const
{
	return (AMateria*)this;
}

void AMateria::use(ICharacter& target)
{
	(void)target;
}
