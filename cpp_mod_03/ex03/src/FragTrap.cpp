/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 09:43:56 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/02 15:10:21 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	_HitPoints = 100;
	_EnergyPoints = 100;
	_AttackDamage = 30;
	std::cout << MAGENTA << "FragTrap " << name << "'s constructor intialized" << RESET << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << MAGENTA << "FragTrap " << _name << "'s destructor called!" << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << MAGENTA << "FragTrap " << other._name << " copy constructor Initialized" << RESET <<std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	return (*this);
}

int	FragTrap::CheckConditions(const std::string& target)
{
	if (_HitPoints <= 0)
	{
		std::cout << RED << "FragTrap " << _name << " is dead so cannot attack " << target << "!" <<RESET << std::endl;
		return (1);
	}
	if (_EnergyPoints == 0)
	{
		std::cout << LIGHT_RED << "FragTrap " << _name << " tried to attack " << target << " but didn't have enough energy!" << RESET << std::endl;
		return (1);
	}
	if (_AttackDamage <= 0)
	{
		std::cout << YELLOW << "FragTrap " << _name << " tries to attack " << target << " but has no Attack Damage. "
			<< _name << " wastes energy whilst trying!" << RESET << std::endl;
		std::cout << YELLOW << "No damage was inflicted." << RESET << std::endl;
		_EnergyPoints--;
		return (1);
	}
	return (0);
}

void FragTrap::attack(const std::string& target)
{
	if (CheckConditions(target) == 1)
		return ;
	std::cout << YELLOW << "FragTrap " << _name << " attacks " << target
		<< " with " << _AttackDamage << " amount of damage!" << YELLOW << std::endl;
	_EnergyPoints--;
	PrintStatus();
}

void FragTrap::highFivesGuys( void )
{
	if (_HitPoints == 0)
	{
		std::cout << LIGHT_CYAN << _name << " is sadly dead so he cannot give you positive high fives..."
			<< RESET << std::endl;
		return ;
	}
	if (_EnergyPoints == 0)
	{
		std::cout << LIGHT_YELLOW << _name << " has no energy so cannot give you those needed high fives."
			<< RESET << std::endl;
		return ;
	}
	std::cout << LIGHT_BLUE << _name << " wants give you some positive high fives. Not negative ones. Positive only!"
		<< RESET << std::endl;
}
