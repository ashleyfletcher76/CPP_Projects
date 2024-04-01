/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:41:46 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/01 17:24:07 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	_HitPoints = 100;
	_EnergyPoints = 50;
	_AttackDamage = 20;
	std::cout << MAGENTA << "ScavTrap " << name << "'s constructor intialized" << RESET << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << MAGENTA << "ScavTrap " << _name << "'s destructor called!" << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << MAGENTA << other._name << " copy constructor Initialized" << RESET <<std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	return (*this);
}
