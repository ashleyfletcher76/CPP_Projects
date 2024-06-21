/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 09:30:55 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/21 12:18:56 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void	correctVersion()
{
	try
	{
		Bureaucrat bureaucrat("David", 5);
		Form formOne("Form 1", 150, 100);

		std::cout << bureaucrat << "\n" << std::endl;
		std::cout << formOne << std::endl;
		bureaucrat.signForm(formOne);
		std::cout << "\n" << formOne << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	tooLowRequired()
{
	try
	{
		Bureaucrat bureaucrat("David", 5);
		Form formOne("Form 1", 151, 100);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	tooLowGradeTosign()
{
	try
	{
		Bureaucrat bureaucrat("David", 102);
		Form formOne("Form 1", 100, 100);

		std::cout << bureaucrat << "\n" << std::endl;
		std::cout << formOne << std::endl;
		bureaucrat.signForm(formOne);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	fullVersion()
{
	Bureaucrat bob("Bob", 24);
	Form formOne;
	std::cout << bob << "\n" << std::endl;
	std::cout << formOne << "\n" << std::endl;
	bob.signForm(formOne);
	std::cout << "\n" << formOne << std::endl;
}

int	main()
{
	//correctVersion();
	//tooLowRequired();
	//tooLowGradeTosign();
	fullVersion();
	return (0);
}
