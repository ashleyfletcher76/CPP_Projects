/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 09:30:55 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/18 18:15:57 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void	testOne()
{
	Bureaucrat bureaucrat("David", 101);
	Form formOne("Form 1", 100, 100);

	std::cout << bureaucrat.getName() << std::endl;
	std::cout << bureaucrat.getGrade() << std::endl;
	std::cout << formOne.getRequiredGradeToSign() << std::endl;
	std::cout << formOne.getRequiredGradeToExecute() << std::endl;
	try
	{
		formOne.beSigned(bureaucrat);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int	main()
{
	testOne();
	return (0);
}
