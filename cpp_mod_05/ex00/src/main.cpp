/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 09:30:55 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/21 11:52:51 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	correctToFail()
{
	try
	{
		Bureaucrat bureaucrat;

		std::cout << "---- Before increment ----" << std::endl;
		std::cout << bureaucrat << std::endl;
		bureaucrat.incrementGrade();
		std::cout << "---- After increment ----" << std::endl;
		std::cout << bureaucrat << std::endl;
		std::cout << "-----------" << std::endl;
		std::cout << "---- Now decrement twice, will throw exception ----" << std::endl;
		bureaucrat.decrementGrade();
		std::cout << bureaucrat << std::endl;
		bureaucrat.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	tooHigh()
{
	try
	{
		Bureaucrat b1("John", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	tooLow()
{
	try
	{
		Bureaucrat b1("John", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	copyConstructor()
{
	try
	{
		Bureaucrat b1("John", 5);
		Bureaucrat b2 = b1;

		std::cout << "----- b1 details -----" << std::endl;
		std::cout << b1 << std::endl;
		std::cout << "----- b2 details -----" << std::endl;
		std::cout << b2 << std::endl;
		b1.incrementGrade();
		std::cout << "---- After incrememnt -----" << std::endl;
		std::cout << "----- b1 details -----" << std::endl;
		std::cout << b1 << std::endl;
		std::cout << "----- b2 details -----" << std::endl;
		std::cout << b2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	copyAssignment()
{
	try
	{
		Bureaucrat b1("John", 5);
		Bureaucrat b2;

		std::cout << "---- b1 details ----" << std::endl;
		std::cout << b1 << std::endl;
		std::cout << "---- b2 details ----" << std::endl;
		std::cout << b2 << std::endl;
		b2 = b1;
		std::cout << "---- b2 details ----" << std::endl;
		std::cout << b2 << std::endl;
		b1.incrementGrade();
		std::cout << "---- After incremement ----" << std::endl;
		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int	main()
{
	correctToFail();
	//tooHigh();
	//tooLow();
	//copyConstructor();
	//copyAssignment();
	return (0);
}
