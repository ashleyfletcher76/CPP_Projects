/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 09:30:55 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/21 13:37:44 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "umbrella.hpp"

int	main()
{
	Intern someRandomIntern;
	srand(time(0));

	AForm* formOne = someRandomIntern.makeForm("robotomy request", "David");
	if (formOne)
	{
		Bureaucrat Bob("Bob", 1);
		formOne->beSigned(Bob);
		Bob.executeForm(*formOne);
		delete (formOne);
	}
	std::cout << "-----------" << std::endl;
	AForm* formTwo = someRandomIntern.makeForm("presidential pardon", "Janine");
	if (formTwo)
		delete (formTwo);
	std::cout << "-----------" << std::endl;
	AForm* formThree = someRandomIntern.makeForm("shrubbery creation", "Petra");
	if (formThree)
		delete (formThree);
	std::cout << "-----------" << std::endl;
	AForm* formFour = someRandomIntern.makeForm("not a form", "Loser");
	if (formFour)
		delete (formFour);
	return (0);
}
