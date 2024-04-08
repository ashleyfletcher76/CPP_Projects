/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 14:59:54 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/08 11:45:41 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

//------Constructors/destructors--------//

Character::Character() : _name(""), _Unequipped(NULL), _UnequippedCount(0)
{
	for (int i = 0; i < InventorySize; i++)
	{
		_Inventory[i] = NULL;
	}
}

Character::~Character()
{
	for (int i = 0; i < InventorySize; i++)
	{
		if (_Inventory[i] != NULL)
		{
			delete _Inventory[i];
			_Inventory[i] = NULL;
		}
	}
	for (unsigned int i = 0; i < _UnequippedCount; i++)
	{
		delete _Unequipped[i];
		_Unequipped[i] = NULL;
	}
	delete[] _Unequipped;
	_Unequipped = NULL;
}

Character::Character(const std::string& name) : _name(name), _Unequipped(NULL), _UnequippedCount(0)
{
	for (int i = 0; i < InventorySize; i++)
		_Inventory[i] = NULL;
}

Character::Character(const Character& other) : _name(other._name)
{
	for (int i = 0; i < InventorySize; i++)
	{
		if (other._Inventory[i])
			_Inventory[i] = other._Inventory[i]->clone();
		else
			_Inventory[i] = NULL;
	}
}

Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		_name = other._name;
		for (int i = 0; i < InventorySize; i++)
		{
			delete _Inventory[i]; // deep copy
			if (other._Inventory[i])
				_Inventory[i] = other._Inventory[i]->clone();
			else
				_Inventory[i] = NULL;
		}
	}
	return (*this);
}

//-------Standard functions--------//

std::string const& Character::getName() const
{
	return (_name);
}

void Character::equip(AMateria* m)
{
	if (!m)
	{
		std::cout << "Equipment full." << std::endl;
		return ;
	}
	for(int i = 0; i < InventorySize; i++)
	{
		if (!_Inventory[i])
		{
			_Inventory[i] = m;
			return ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 4 || !this->_Inventory[idx])
	{
		std::cout << "Nothing to unequip." << std::endl;
		return ;
	}
	Trash(_Inventory[idx], _UnequippedCount);
	_Inventory[idx] = NULL; // removes from the inventory
}

void Character::Trash(AMateria* materia, unsigned int &count)
{
	AMateria** temp = new AMateria*[count + 1];
	for (unsigned int i = 0; i < count; i++)
		temp[i] = _Unequipped[i];
	temp[count] = materia;
	delete[] _Unequipped;
	_Unequipped = temp;
	count++;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= InventorySize || !_Inventory[idx])
	{
		std::cout << "Nothing to use." << std::endl;
		return ;
	}
	_Inventory[idx]->use(target);
}
