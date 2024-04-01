/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:36:04 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/01 14:10:02 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// int	main( void )
// {
// 	ClapTrap FirstPerson("Dave");
// 	FirstPerson.attack("Johnathan");
// 	FirstPerson.beRepaired(10);
// 	FirstPerson.takeDamage(15);
// 	FirstPerson.attack("Johnathan");
// 	FirstPerson.beRepaired(5);
// }

int	main( void )
{
	ClapTrap FirstPerson("Dave");
	FirstPerson.attack("Johnathan");
	FirstPerson.beRepaired(10);
	FirstPerson.takeDamage(25);
	FirstPerson.attack("Johnathan");
	FirstPerson.beRepaired(5);
}

// int	main( void )
// {
// 	ClapTrap FirstPerson("Dave");
// 	FirstPerson.attack("Target 1");
// 	FirstPerson.attack("Target 2");
// 	FirstPerson.attack("Target 3");
// 	FirstPerson.attack("Target 4");
// 	FirstPerson.attack("Target 5");
// 	FirstPerson.attack("Target 6");
// 	FirstPerson.attack("Target 7");
// 	FirstPerson.attack("Target 8");
// 	FirstPerson.attack("Target 9");
// 	FirstPerson.attack("Target 10");
// 	FirstPerson.attack("Target 11");
// }
