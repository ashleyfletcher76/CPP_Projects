/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 09:30:55 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/18 16:35:35 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void	testOne()
{
	Bureaucrat bureaucrat;
	Form formOne("John", 100, 90);

	std::cout << formOne.getName() << std::endl;
	std::cout << formOne.getGrade() << std::endl;
	try
	{
		bureaucrat.incrementGrade();
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
