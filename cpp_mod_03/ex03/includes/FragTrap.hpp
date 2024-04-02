/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 09:43:59 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/02 11:04:19 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
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
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	private:

	public:
		FragTrap(const std::string& name);
		~FragTrap();
		FragTrap(const FragTrap& other);
		FragTrap& operator=(const FragTrap& other);

		void attack(const std::string& target);
		int	CheckConditions(const std::string& target);
		void highFivesGuys( void );
};

#endif
