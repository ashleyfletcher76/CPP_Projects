/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 09:30:55 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/18 12:31:01 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void	testOne()
{
	Bureaucrat bureaucrat;

	std::cout << bureaucrat.getName() << std::endl;
	std::cout << bureaucrat.getGrade() << std::endl;
	try
	{
		bureaucrat.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	testTwo()
{
	try
	{
		Bureaucrat b1("John", 101);
		std::cout << b1.getName() << std::endl;
		std::cout << b1.getGrade() << std::endl;
		b1.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

}

void	testThree()
{
	try
	{
		Bureaucrat b1("John", 151);
		std::cout << b1.getName() << std::endl;
		std::cout << b1.getGrade() << std::endl;
		b1.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

}

void	testFour()
{
	try
	{
		Bureaucrat b1("John", -5);
		std::cout << b1.getName() << std::endl;
		std::cout << b1.getGrade() << std::endl;
		b1.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

}

void	testFive()
{
	try
	{
		Bureaucrat b1("John", 5);
		Bureaucrat b2;
		std::cout << b1.getName() << std::endl;
		std::cout << b1.getGrade() << std::endl;
		std::cout << b2.getName() << std::endl;
		std::cout << b2.getGrade() << std::endl;
		b2 = b1;
		std::cout << b2.getName() << std::endl;
		std::cout << b2.getGrade() << std::endl;
		b1.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

}

int	main()
{
	// testOne();
	// testTwo();
	// testThree();
	// testFour();
	testFive();
	return (0);
}
