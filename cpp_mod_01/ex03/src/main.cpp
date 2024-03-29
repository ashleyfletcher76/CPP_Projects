/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:00:50 by asfletch          #+#    #+#             */
/*   Updated: 2024/03/29 08:28:36 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

// int main( void )
// {
// 	{
// 		Weapon club = Weapon("crude spiked club");

// 		HumanA bob("Bob", club);
// 		bob.attack();
// 		club.setType("some other type of club");
// 		bob.attack();
// 	}
// 	{
// 		Weapon club = Weapon("crude spiked club");

// 		HumanB jim("Jim");
// 		jim.attack();
// 		jim.setWeapon(club);
// 		jim.attack();
// 		club.setType("some other type of club");
// 		jim.attack();
// 	}
// 	return 0;
// }

int main( void )
{
	{
		Weapon type = Weapon("chickens");

		HumanA dave("Dave", type);
		dave.attack();
		type.setType("pink rubber gloves");
		dave.attack();
	}
	{
		Weapon type = Weapon("toaster");

		HumanB jeremiah("Jeremiah");
		jeremiah.attack();
		jeremiah.setWeapon(type);
		jeremiah.attack();
		type.setType("plastic rubber duck");
		jeremiah.attack();
	}
	return 0;
}
