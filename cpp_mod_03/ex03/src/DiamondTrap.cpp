/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 11:18:14 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/03 10:38:50 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), name(name)
{
	std::cout << MAGENTA << "DiamondTrap " << this->name << "'s constructor intialized"
		<< RESET << std::endl;
		_HitPoints = 100;
		_EnergyPoints = 50;
		_AttackDamage = 30;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << MAGENTA << "DiamondTrap " << this->name << "'s destructor is called!"
		<< RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other._name), FragTrap(other),
	ScavTrap(other), name(other.name)
{
	std::cout << MAGENTA << "DiamondTrap " << this->name << "'s copy constructor Initialized"
		<< RESET <<std::endl;
	_name = other._name;
	_HitPoints = other._HitPoints;
	_EnergyPoints = other._EnergyPoints;
	_AttackDamage = other._AttackDamage;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		FragTrap::operator=(other);
		ScavTrap::operator=(other);
		_name = other._name;
		std::cout << MAGENTA << "DiamondTrap's copy assignment initialized"
			<< RESET << std::endl;
	}
	return (*this);
}

void DiamondTrap::whoAmI( void )
{
	std::cout << "DiamondTrap's name: " << this->name << std::endl;
	std::cout << "ClapTrap's name: " << ClapTrap::_name << std::endl;
}

