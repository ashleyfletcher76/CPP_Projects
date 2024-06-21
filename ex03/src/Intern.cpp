/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:49:06 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/21 13:22:40 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

//------------Orthodox/constructors-----------//

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern& other) {(void)other;}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return (*this);
}

//------------Main Functions-------------//

AForm* createPresidentialPardonForm(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

AForm* createRobotomyRequestForm(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

AForm* createShrubberyCreationForm(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::makeForm(std::string name, const std::string &target)
{
	typedef AForm* (*FormCreator)(const std::string &target); // matches to functions with this signature
	struct FormType
	{
		std::string name;
		FormCreator creator;
	};
	static const FormType formTypes[] =
	{
		{"robotomy request", createRobotomyRequestForm},
		{"presidential pardon", createPresidentialPardonForm},
		{"shrubbery creation", createShrubberyCreationForm}
	};
	for (size_t i = 0; i < 3; ++i)
	{
		if (formTypes[i].name == name)
		{
			std::cout << "Intern creates " << name << std::endl;
			return (formTypes[i].creator(target));
		}
	}
	std::cout << "Error in form name: " << name
		<< "\nTry again. Valid form names are: robotomy request, presidential pardon\nor shrubbery creation" << std::endl;
			return (NULL);
}
