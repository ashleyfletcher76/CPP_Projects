/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapConstru.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:07:28 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/02 15:20:19 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name) : _name(name), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0)
{
	std::cout << MAGENTA << "ClapTrap " << _name << "'s constructor is intialized" << RESET << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << MAGENTA << "ClapTrap " << _name << "'s destructor is called!" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : _name(other._name), _HitPoints(other._HitPoints),
	 _EnergyPoints(other._EnergyPoints), _AttackDamage(other._AttackDamage)
{
	std::cout << MAGENTA << "ClapTrap " << _name << "'s copy constructor is initialized" << RESET << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		std::cout << MAGENTA << "ClapTrap " << _name << "'s copy assignment initialized" << RESET << std::endl;
		_name = other._name;
		_HitPoints = other._HitPoints;
		_EnergyPoints = other._EnergyPoints;
		_AttackDamage = other._AttackDamage;
	}
	return (*this);
}
