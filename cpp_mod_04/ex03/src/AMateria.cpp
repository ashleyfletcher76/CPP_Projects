/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:09:50 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/06 14:50:48 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("")
{
	std::cout << "AMateria has been created" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "AMateria of type: " << _type << " has been destroyed"
		<< std::endl;
}

AMateria::Amateria(const Amateria& other) : _type(other._type) {}

AMateria& AMateria::operator=(const AMateria& other)
{
	if (this != &other)
	{
		(void)other;
	}
	return (*this);
}

std::string AMateria::const& getType() const
{
	return (_type);
}

AMateria* Amateria::clone() {}

void AMateria::use(ICharacter& target)	{}
