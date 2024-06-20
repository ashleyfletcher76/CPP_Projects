/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 09:30:55 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/20 12:12:14 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void	tooHighRequired()
{
	try
	{
		Bureaucrat bureaucrat("David", 5);
		Form formOne("Form 1", 151, 100);

		std::cout << bureaucrat.getName() << std::endl;
		std::cout << bureaucrat.getGrade() << std::endl;
		std::cout << formOne.getRequiredGradeToSign() << std::endl;
		std::cout << formOne.getRequiredGradeToExecute() << std::endl;
		bureaucrat.signForm(formOne);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	tooHighGrade()
{
	try
	{
		Bureaucrat bureaucrat("David", 0);
		Form formOne("Form 1", 151, 100);

		std::cout << bureaucrat.getName() << std::endl;
		std::cout << bureaucrat.getGrade() << std::endl;
		std::cout << formOne.getRequiredGradeToSign() << std::endl;
		std::cout << formOne.getRequiredGradeToExecute() << std::endl;
		bureaucrat.signForm(formOne);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	tooLowGrade()
{
	try
	{
		Bureaucrat bureaucrat("David", 102);
		Form formOne("Form 1", 100, 100);

		std::cout << bureaucrat.getName() << std::endl;
		std::cout << bureaucrat.getGrade() << std::endl;
		std::cout << formOne.getRequiredGradeToSign() << std::endl;
		std::cout << formOne.getRequiredGradeToExecute() << std::endl;
		bureaucrat.signForm(formOne);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	test()
{
	Bureaucrat bob("Bob", 24);
	Form formOne;
	std::cout << formOne << std::endl;
	bob.signForm(formOne);
	std::cout << formOne << std::endl;
}

int	main()
{
	//tooHighRequired();
	//tooLowGrade();
	//tooHighGrade();
	test();
	return (0);
}
