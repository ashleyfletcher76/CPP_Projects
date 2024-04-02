/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 11:18:14 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/02 15:16:37 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), name(name)
{
	std::cout << MAGENTA << "DiamondTrap " << this->name << "'s constructor intialized" << RESET << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << MAGENTA << "DiamondTrap " << this->name << "'s destructor is called!" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), FragTrap(other),
	ScavTrap(other), name(other.name)
{
	std::cout << MAGENTA << "DiamondTrap " << this->name << "'s copy constructor Initialized" << RESET <<std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		std::cout << MAGENTA << "DiamondTrap's copy assignment initialized" << RESET << std::endl;
	}
	return (*this);
}

void DiamondTrap::whoAmI( void )
{
	std::cout << "DiamondTrap's name: " << this->name << std::endl;
	std::cout << "ClapTrap's name: " << ClapTrap::_name << std::endl;
}

void DiamondTrap::PrintStatusDiamond( void )
{
	std::cout << std::endl;
	std::cout << CYAN << "-----Health status------" << std::endl;
	std::cout << _name << ": Hit points = " << _HitPoints << " Energy points = "
		<< _EnergyPoints << " Attack damage = " << _AttackDamage << std::endl;
	std::cout << "------------------------" << RESET << std::endl;
	std::cout << std::endl;
}
