/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 09:53:20 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/01 16:55:28 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void ClapTrap::PrintStatus( void )
{
	std::cout << std::endl;
	std::cout << CYAN << "-----Health status------" << std::endl;
	std::cout << _name << ": Hit points = " << _HitPoints << " Energy points = "
		<< _EnergyPoints << " Attack damage = " << _AttackDamage << std::endl;
	std::cout << "------------------------" << RESET << std::endl;
	std::cout << std::endl;
}

int	ClapTrap::CheckConditions(const std::string& target)
{
	if (_HitPoints <= 0)
	{
		std::cout << RED << _name << " is dead so cannot attack!" << RESET << std::endl;
		return (1);
	}
	if (_EnergyPoints == 0)
	{
		std::cout << LIGHT_RED << _name << " tried to attack " << target
			<< " but didn't have enough energy!" << RESET << std::endl;
		return (1);
	}
	if (_AttackDamage <= 0)
	{
		std::cout << YELLOW << _name << " attacks " << target << " with "
			<< _AttackDamage << " amount of damage!" << RESET << std::endl;
		std::cout << YELLOW << "No damage was inflicted." << RESET << std::endl;
		_EnergyPoints--;
		return (1);
	}
	return (0);
}

void ClapTrap::attack(const std::string& target)
{
	if (CheckConditions(target) == 1)
		return ;
	std::cout << YELLOW << _name << " attacks " << target << " with " << _AttackDamage
		<< " amount of damage!" << YELLOW << std::endl;
	_EnergyPoints--;
	PrintStatus();
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_HitPoints <= 0)
	{
		std::cout << RED << _name << " is already dead. Cannot receive more damage!" << RESET << std::endl;
		_HitPoints = 0;
		PrintStatus();
		std::cout << std::endl;
		return ;
	}
	_HitPoints -= amount;
	if (_HitPoints <= 0)
	{
		std::cout << RED << _name << " took " << amount << " of damage and is now dead."
			<< RESET << std::endl;
		_HitPoints = 0;
		PrintStatus();
		return ;
	}
	if (_AttackDamage > 0)
	{
		std::cout << RED << _name << " took " << amount << " of damage." << RESET << std::endl;
		PrintStatus();
		return ;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_EnergyPoints <= 0)
	{
		std::cout << RED << _name << " cannot be repaired because they have no energy."
			<< RESET << std::endl;
		PrintStatus();
		return ;
	}
	_HitPoints += amount;
	_EnergyPoints--;
	std::cout << GREEN << _name << " has been repaired by " << amount
		<< " amount of points!" << RESET << std::endl;
	PrintStatus();
}
