/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 09:30:55 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/21 15:48:17 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "umbrella.hpp"
#include <ctime>
#include <cstdlib>

void	ShrubFailure()
{
	try
	{
		Bureaucrat Neil("Neil", 147);
		ShrubberyCreationForm Shrub("Home");
		Neil.signForm(Shrub);
		Neil.executeForm(Shrub);
		std::ifstream file("Home_shrubbery");
		if (!file.is_open())
		{
			std::cerr << "Failed to create/open file" << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	ShrubSuccess()
{
	try
	{
		Bureaucrat Neil("Neil", 54);
		ShrubberyCreationForm Shrub("Home");
		Neil.signForm(Shrub);
		Neil.executeForm(Shrub);
		std::ifstream file("Home_shrubbery");
		if (!file.is_open())
		{
			std::cerr << "Failed to create/open file" << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	PrezTest()
{
	try
	{
		Bureaucrat Bob("Bob", 25);
		PresidentialPardonForm PrezOne("Arthur Dent");
		Bob.signForm(PrezOne);
		Bob.executeForm(PrezOne);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "--------------" << std::endl;
	try
	{
		Bureaucrat Dave("Dave", 2);
		PresidentialPardonForm PrezOne("Arthur Dent");
		Dave.signForm(PrezOne);
		Dave.executeForm(PrezOne);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	RoboTest()
{
	try
	{
		Bureaucrat Bob("Bob", 25);
		RobotomyRequestForm RoboForm("RoboForm");
		Bob.signForm(RoboForm);
		for(int i = 0; i < 5; i++)
		{
			Bob.executeForm(RoboForm);
			std::cout << "-------------" << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	checkOperators()
{
	RobotomyRequestForm RoboOne("Home");
	RobotomyRequestForm RoboTwo = RoboOne;
	RobotomyRequestForm RoboThree("Test");
	Bureaucrat Bob("Bob", 5);

	std::cout << RoboOne << "\n" << std::endl;
	std::cout << RoboTwo << "\n" << std::endl;
	std::cout << RoboThree << "\n" << std::endl;
	Bob.signForm(RoboTwo);
	RoboThree = RoboTwo;
	std::cout << RoboOne << "\n" << std::endl;
	std::cout << RoboTwo << "\n" << std::endl;
	std::cout << RoboThree << std::endl;
}

int	main()
{
	srand(time(0));
	//RoboTest();
	//PrezTest();
	//ShrubSuccess();
	ShrubFailure();
	//checkOperators();
	return (0);
}
