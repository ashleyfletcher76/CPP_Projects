/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:36:04 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/01 17:26:00 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

// int	main( void )
// {
// 	ClapTrap FirstPerson("Dave");
// 	FirstPerson.attack("Johnathan");
// 	FirstPerson.beRepaired(10);
// 	FirstPerson.takeDamage(15);
// 	FirstPerson.attack("Johnathan");
// 	FirstPerson.beRepaired(5);

// 	std::cout << "--------------" << std::endl;
// 	std::cout << "--------------" << "\n" << std::endl;

// 	ScavTrap SecondPerson("Cole");
// 	SecondPerson.attack("Burty");
// 	SecondPerson.beRepaired(0);
// 	SecondPerson.takeDamage(85);
// 	SecondPerson.takeDamage(20);
// 	SecondPerson.attack("Burty");
// 	SecondPerson.beRepaired(40);
// 	SecondPerson.attack("Burty");
// }

int	main( void )
{
	ClapTrap FirstPerson("Dave");
	FirstPerson.attack("Johnathan");
	FirstPerson.beRepaired(10);
	FirstPerson.takeDamage(25);
	FirstPerson.attack("Johnathan");
	FirstPerson.beRepaired(5);

	std::cout << "--------------" << std::endl;
	std::cout << "--------------" << "\n" << std::endl;

	ScavTrap SecondPerson("Derick");
	SecondPerson.attack("Jimbo");
	SecondPerson.beRepaired(10);
	SecondPerson.takeDamage(25);
	SecondPerson.attack("Jimbo");
	SecondPerson.beRepaired(5);
}

// int	main( void )
// {
// 	ClapTrap FirstPerson("June");
// 	for (int i = 0; i < 11; i++)
// 		FirstPerson.attack("Target");
// 	std::cout << "-------------\n";
// 	std::cout << "-------------" << std::endl;
// 	ClapTrap SecondPerson("Johno");
// 	for (int i = 0; i < 11; i++)
// 		SecondPerson.attack("Target");
// }
