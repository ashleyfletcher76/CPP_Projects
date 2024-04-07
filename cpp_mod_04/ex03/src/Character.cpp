/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 14:59:54 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/07 16:28:49 by asfletch         ###   ########.fr       */
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
		// if (_Unequipped[i] != NULL)
		// {
			delete _Unequipped[i];
			_Unequipped[i] = NULL;
		// }
	}
	delete[] _Unequipped;
	_Unequipped = NULL;
}

Character::Character(const std::string& name) : _name(name), _Unequipped(NULL), _UnequippedCount(0)
{
	for (int i = 0; i < InventorySize; i++)
	{
		_Inventory[i] = NULL;
	}
}

Character::Character(const Character& other) : _name(other._name)
{
	for (int i = 0; i < InventorySize; i++)
		_Inventory[i] = other._Inventory[i] ? other._Inventory[i]->clone() : NULL;
}

Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		_name = other._name;
		for (int i = 0; i < InventorySize; i++)
		{
			delete _Inventory[i];
			_Inventory[i] = other._Inventory[i] ? other._Inventory[i]->clone() : NULL;
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
		return ; // Full
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
		return ;
	AMateria** temp = new AMateria*[_UnequippedCount + 1];
	for (unsigned int i = 0; i < _UnequippedCount; i++)
		temp[i] = _Unequipped[i];
	// temp[_UnequippedCount] = _Inventory[idx];
	// delete[] _Unequipped;
	// _Unequipped = temp;
	// _UnequippedCount++;
	Trash(temp, _UnequippedCount);
	_Inventory[idx] = NULL; // removes from the inventory
}

void Character::Trash(AMateria** temp, int idx)
{
	temp[_UnequippedCount] = _Inventory[idx];
	delete[] _Unequipped;
	_Unequipped = temp;
	_UnequippedCount++;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= InventorySize || !_Inventory[idx])
		return ;
	_Inventory[idx]->use(target);
}
