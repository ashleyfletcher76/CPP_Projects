/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 14:35:22 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/08 13:05:12 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < MaxTemplates; i++)
		_Templates[i] = NULL;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < MaxTemplates; i++)
	{
		if (_Templates[i])
		{
			delete _Templates[i];
			_Templates[i] = NULL;
		}
	}
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	for (int i = 0; i < MaxTemplates; i++)
		_Templates[i] = other._Templates[i] ? other._Templates[i]->clone() : NULL; //deep copy
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other) //compares addresses
	{
		for (int i = 0; i < MaxTemplates; i++)
		{
			delete _Templates[i];
			_Templates[i] = other._Templates[i] ? other._Templates[i]->clone() : NULL; // ensures deep copy
		}
	}
	return (*this);
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < MaxTemplates; i++)
	{
		if (_Templates[i] != NULL)
		{
			if (_Templates[i]->getType() == type)
				return (_Templates[i]->clone());
		}
	}
	return (NULL);
}

void MateriaSource::learnMateria(AMateria* materia)
{
	for (int i = 0; i < MaxTemplates; i++)
	{
		if (!_Templates[i]) // check if empty
		{
			_Templates[i] = materia;
			return ;
		}
	}
}
