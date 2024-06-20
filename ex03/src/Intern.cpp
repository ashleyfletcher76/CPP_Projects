/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:49:06 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/20 17:02:23 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() :
	AForm("Intern", 25, 5), _target("Default Intern") {}

Intern::~Intern() {}

Intern::Intern(const Intern& other) : _target(other._target)
{
	//std::cout << "Intern's copy constructor initialized" <<std::endl;
}

Intern& Intern::operator=(const Intern& other)
{
	if (this != &other)
	{
		//std::cout << "PresidentialPardonForm's copy assignment initialized" << std::endl;
		_target = other._target;
	}
	return (*this);
}

AForm* Intern::makeForm(std::string name, const std::string &target) {}
