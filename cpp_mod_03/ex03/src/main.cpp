/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:36:04 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/02 18:05:32 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

void	FirstCase( void )
{
	std::cout << std::endl;
	std::cout << "------TEST CASE 1--------" << std::endl;
	std::cout << "-------------------------" << "\n" << std::endl;
	ClapTrap FirstPerson("Dave");
	FirstPerson.attack("Johnathan");
	FirstPerson.beRepaired(10);
	FirstPerson.takeDamage(25);
	FirstPerson.attack("Johnathan");
	FirstPerson.beRepaired(5);
}

void	SecondCase( void )
{
	std::cout << std::endl;
	std::cout << "------TEST CASE 2--------" << std::endl;
	std::cout << "-------------------------" << "\n" << std::endl;
	ScavTrap FirstPerson("Derick");
	FirstPerson.attack("Jimbo");
	FirstPerson.beRepaired(10);
	FirstPerson.takeDamage(25);
	FirstPerson.guardGate();
	ScavTrap SecondPerson = FirstPerson;
	SecondPerson.PrintStatus();
	FirstPerson.attack("Jimbo");
	FirstPerson.beRepaired(5);
	SecondPerson.PrintStatus();
}

void	ThirdCase( void )
{
	std::cout << std::endl;
	std::cout << "------TEST CASE 3--------" << std::endl;
	std::cout << "-------------------------" << "\n" << std::endl;
	ClapTrap FirstPerson("June");
	for (int i = 0; i < 11; i++)
		FirstPerson.attack("Target");
	std::cout << "-------------\n";
	std::cout << "-------------" << std::endl;
	ScavTrap SecondPerson("Johno");
	for (int i = 0; i < 11; i++)
		SecondPerson.attack("Target");
	SecondPerson.guardGate();
	SecondPerson.takeDamage(120);
	SecondPerson.guardGate();
}

void	FourthCase( void )
{
	std::cout << std::endl;
	std::cout << "------TEST CASE 5--------" << std::endl;
	std::cout << "-------------------------" << "\n" << std::endl;
	ClapTrap FirstPerson("Dave");
	FirstPerson.attack("Johnathan");
	FirstPerson.beRepaired(10);
	FirstPerson.takeDamage(15);
	FirstPerson.attack("Johnathan");
	FirstPerson.beRepaired(5);

	std::cout << "--------------" << std::endl;
	std::cout << "--------------" << "\n" << std::endl;

	ScavTrap SecondPerson("Cole");
	SecondPerson.attack("Burty");
	SecondPerson.beRepaired(0);
	SecondPerson.takeDamage(85);
	SecondPerson.takeDamage(20);
	SecondPerson.attack("Burty");
	SecondPerson.beRepaired(40);
	SecondPerson.attack("Burty");
}

void	FifthCase( void )
{
	ClapTrap FirstPerson("Desmond");
	ClapTrap SecondPerson = FirstPerson;

	FirstPerson.PrintStatus();
	SecondPerson.PrintStatus();

	std::cout << "--------------" << std::endl;
	std::cout << "--------------" << "\n" << std::endl;
	ClapTrap ThirdPerson("David");
	ThirdPerson.PrintStatus();
	FirstPerson.attack("Johno");
	std::cout << RED << "Second person's status" << RESET << std::endl;
	SecondPerson.PrintStatus();
	std::cout << BLUE << "Copy assignment operator for third person" << RESET << std::endl;
	ThirdPerson = FirstPerson;
	std::cout << RED << "Second person's status" << RESET << std::endl;
	ThirdPerson.PrintStatus();
}

void	SixthCase( void )
{
	ClapTrap FirstPerson("Desmond");
	ScavTrap SecondPerson("David");
	ClapTrap ThirdPerson = FirstPerson;
	ScavTrap FourthPerson("Johno");

	FirstPerson.PrintStatus();
	SecondPerson.PrintStatus();
	ThirdPerson.PrintStatus();
	FourthPerson.PrintStatus();
	SecondPerson.attack("Dave");
	FourthPerson = SecondPerson;
	FourthPerson.PrintStatus();
}

void	SeventhCase( void )
{
	ClapTrap FirstPerson("Dezza");
	FirstPerson.attack("jim");
	ScavTrap SecondPerson("Tim");
	SecondPerson.attack("Dezza");
	SecondPerson.beRepaired(5);
	SecondPerson.takeDamage(110);
	ScavTrap ThirdPerson("Gary");
	ThirdPerson.PrintStatus();
	ThirdPerson = SecondPerson;
	ThirdPerson.PrintStatus();
	ThirdPerson.guardGate();
	ThirdPerson.beRepaired(60);
	ThirdPerson.guardGate();
	SecondPerson.PrintStatus();
	FragTrap FourthPerson("Tesse");
	FourthPerson.highFivesGuys();
	FourthPerson.takeDamage(25);
	FourthPerson.attack("Yasmin");
}

void	EigthCase( void )
{
	DiamondTrap FirstPerson("Dave");

	FirstPerson.whoAmI();
	DiamondTrap SecondPerson("Jimmy");
	SecondPerson = FirstPerson;
	SecondPerson.PrintStatus();
	FirstPerson.attack("Johnno");
	DiamondTrap ThirdPerson = FirstPerson;
	ThirdPerson.PrintStatus();
	ThirdPerson.takeDamage(20);
}

void	NinthCase( void )
{
	DiamondTrap FirstPerson("Dave");

	FirstPerson.PrintStatus();
	FirstPerson.attack("Johno");
	FirstPerson.beRepaired(10);
	FirstPerson.guardGate();
	FirstPerson.highFivesGuys();
	FirstPerson.takeDamage(10);
}

int	main( void )
{
	// FirstCase();
	SecondCase();
	// ThirdCase();
	//FourthCase();
	// FifthCase();
	//SixthCase();
	//SeventhCase();
	//EigthCase();
	//NinthCase();
}
