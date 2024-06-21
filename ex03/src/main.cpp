/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 09:30:55 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/21 10:43:51 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "umbrella.hpp"

int	main()
{
	Intern someRandomIntern;

	AForm* formOne = someRandomIntern.makeForm("robotomy request", "David");
	if (formOne)
		delete (formOne);
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
