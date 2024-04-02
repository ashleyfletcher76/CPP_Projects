/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 09:43:56 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/02 10:40:27 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	_HitPoints = 100;
	_EnergyPoints = 50;
	_AttackDamage = 20;
	std::cout << MAGENTA << "FragTrap " << name << "'s constructor intialized" << RESET << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << MAGENTA << "FragTrap " << _name << "'s destructor called!" << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << MAGENTA << other._name << " copy constructor Initialized" << RESET <<std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	return (*this);
}

// void FragTrap::highFivesGuys( void )
// {

// }
