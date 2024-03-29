/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:59:04 by asfletch          #+#    #+#             */
/*   Updated: 2024/03/27 14:01:33 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	_name = name;
	_weapon = NULL;
}
HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon& weapon)
{
	_weapon = &weapon;
}

void HumanB::attack( void )
{
	if (!_weapon)
	{
		std::cout << _name << " attacks with their bare fists" << std::endl;
	}
	else
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}
