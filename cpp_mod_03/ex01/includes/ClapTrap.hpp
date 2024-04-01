/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 09:51:53 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/01 16:56:23 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define LIGHT_RED     "\x1b[91m"
#define LIGHT_GREEN   "\x1b[92m"
#define LIGHT_YELLOW  "\x1b[93m"
#define LIGHT_BLUE    "\x1b[94m"
#define LIGHT_MAGENTA "\x1b[95m"
#define LIGHT_CYAN    "\x1b[96m"
#define RESET   "\x1b[0m"

#include <iostream>
#include <string>

class ClapTrap
{
	protected:
		std::string _name;
		int _HitPoints;
		int _EnergyPoints;
		int _AttackDamage;

	public:
		ClapTrap(const std::string& name);
		~ClapTrap();
		ClapTrap(const ClapTrap& other);
		ClapTrap& operator=(const ClapTrap& other);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		int	CheckConditions(const std::string& target);
		void PrintStatus( void );
};

#endif
