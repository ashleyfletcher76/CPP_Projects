/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:41:46 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/02 16:25:48 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	_HitPoints = 100;
	_EnergyPoints = 50;
	_AttackDamage = 20;
	std::cout << MAGENTA << "ScavTrap" << "'s constructor intialized" << RESET << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << MAGENTA << "ScavTrap" << "'s destructor called!" << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << MAGENTA << other._name << " copy constructor Initialized" << RESET <<std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other)
	{
		_HitPoints = other._HitPoints;
		_EnergyPoints = other._EnergyPoints;
		_AttackDamage = other._AttackDamage;
		_name = other._name;
		std::cout << MAGENTA << "ScavTrap" << other._name << "'s copy assignment initialized" << RESET << std::endl;
	}
	return (*this);
}

int	ScavTrap::CheckConditions(const std::string& target)
{
	if (_HitPoints <= 0)
	{
		std::cout << RED << "ScavTrap " << _name << " is dead so cannot attack " << target << "!" <<RESET << std::endl;
		return (1);
	}
	if (_EnergyPoints == 0)
	{
		std::cout << LIGHT_RED << "ScavTrap " << _name << " tried to attack " << target << " but didn't have enough energy!" << RESET << std::endl;
		return (1);
	}
	if (_AttackDamage <= 0)
	{
		std::cout << YELLOW << "ScavTrap " << _name << " tries to attack " << target << " but has no Attack Damage. "
			<< _name << " wastes energy whilst trying!" << RESET << std::endl;
		std::cout << YELLOW << "No damage was inflicted." << RESET << std::endl;
		_EnergyPoints--;
		return (1);
	}
	return (0);
}

void ScavTrap::attack(const std::string& target)
{
	if (CheckConditions(target) == 1)
		return ;
	std::cout << YELLOW << "ScavTrap " << _name << " attacks " << target << " with " << _AttackDamage << " amount of damage!" << YELLOW << std::endl;
	_EnergyPoints--;
	PrintStatus();
}

void ScavTrap::guardGate( void )
{
	if (_HitPoints == 0)
	{
		std::cout << LIGHT_CYAN << _name << " cannot keep guard because he's dead." << RESET << std::endl;
		return ;
	}
	if (_EnergyPoints == 0)
	{
		std::cout << LIGHT_YELLOW << _name << " has no energy so cannot keep guard." << RESET << std::endl;
		return ;
	}
	std::cout << LIGHT_BLUE << _name << " is keeping guard cos he doesn't want anybody to eat his chicken nuggets!"
		<< RESET << std::endl;
}
