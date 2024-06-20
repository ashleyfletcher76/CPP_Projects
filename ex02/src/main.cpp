/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 09:30:55 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/20 11:50:23 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

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

void	testOne()
{
	srand(time(0));
}

int	main()
{
	//tooHighRequired();
	//tooLowGrade();
	//tooHighGrade();
	testOne();
	return (0);
}
