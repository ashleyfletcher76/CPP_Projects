/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 09:53:20 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/01 14:11:17 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	ClapTrap::CheckConditions(const std::string& target)
{
	if (_HitPoints <= 0)
	{
		std::cout << RED << _name << " is dead so cannot attack!" << RESET << std::endl;
		return (1);
	}
	if (_EnergyPoints == 0)
	{
		std::cout << LIGHT_RED << _name << " tried to attack " << target << " but didn't have enough energy!" << RESET << std::endl;
		return (1);
	}
	if (_AttackDamage <= 0)
	{
		std::cout << YELLOW << _name << " attacks " << target << " with " << _AttackDamage << " amount of damage!" << RESET << std::endl;
		std::cout << LIGHT_BLUE << "No damage was inflicted." << RESET << std::endl;
		_EnergyPoints--;
		return (1);
	}
	return (0);
}

void ClapTrap::attack(const std::string& target)
{
	if (CheckConditions(target) == 1)
		return ;
	std::cout << YELLOW << _name << " attacks " << target << " with " << _AttackDamage << " amount of damage!" << YELLOW << std::endl;
	_EnergyPoints--;
	std::cout << std::endl;
	std::cout << CYAN << "-----Health status------" << std::endl;
	std::cout << _name << ": Hit points = " << _HitPoints << " Energy points = "
		<< _EnergyPoints << " Attack damage = " << _AttackDamage << std::endl;
	std::cout << "------------------------" << RESET << std::endl;
	std::cout << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	_HitPoints -= amount;
	if (_HitPoints <= 0)
	{
		std::cout << RED << _name << " took " << amount << " of damage and is now dead." << RESET << std::endl;
		_HitPoints = 0;
			std::cout << std::endl;
		std::cout << CYAN << "-----Health status------" << std::endl;
		std::cout << _name << ": Hit points = " << _HitPoints << " Energy points = "
			<< _EnergyPoints << " Attack damage = " << _AttackDamage << std::endl;
		std::cout << "------------------------" << RESET <<std::endl;
		std::cout << std::endl;
		return ;
	}
	if (_AttackDamage > 0)
	{
		std::cout << RED << _name << " took " << amount << " of damage." << RESET << std::endl;
		std::cout << std::endl;
		std::cout << CYAN << "-----Health status------" << std::endl;
		std::cout << _name << ": Hit points = " << _HitPoints << " Energy points = "
			<< _EnergyPoints << " Attack damage = " << _AttackDamage << std::endl;
		std::cout << "------------------------" << RESET << std::endl;
		std::cout << std::endl;
		return ;
	}
	std::cout << YELLOW << "No damage possible because no Attack Damage has been set." << RESET << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_EnergyPoints <= 0)
	{
		std::cout << RED << _name << " cannot be repaired because they have no energy." << RESET << std::endl;
		std::cout << std::endl;
		std::cout << CYAN << "-----Health status------" << std::endl;
		std::cout << _name << ": Hit points = " << _HitPoints << " Energy points = "
		<< _EnergyPoints << " Attack damage = " << _AttackDamage << std::endl;
		std::cout << "------------------------" << RESET << std::endl;
		std::cout << std::endl;
		return ;
	}
	_HitPoints += amount;
	_EnergyPoints--;
	std::cout << GREEN << _name << " has been repaired by " << amount << " amount of points!" << RESET << std::endl;
	std::cout << std::endl;
	std::cout << CYAN << "-----Health status------" << std::endl;
	std::cout << _name << ": Hit points = " << _HitPoints << " Energy points = "
		<< _EnergyPoints << " Attack damage = " << _AttackDamage << std::endl;
	std::cout << "------------------------" << RESET << std::endl;
	std::cout << std::endl;
}
