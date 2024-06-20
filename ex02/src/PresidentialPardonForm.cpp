/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:44:08 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/20 16:40:36 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

//------------Orthodox/constructors-----------//

PresidentialPardonForm::PresidentialPardonForm() :
	AForm("PresidentialPardonForm", 25, 5), _target("Default Prez") {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : _target(other._target)
{
	//std::cout << "PresidentialPardonForm's copy constructor initialized" <<std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		//std::cout << "PresidentialPardonForm's copy assignment initialized" << std::endl;
		_target = other._target;
	}
	return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) :
	AForm("PresidentialPardonForm", 25, 5), _target(target) {}

//------------Main Functions-------------//

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!checkSigned())
		throw FormNotSigned();
	if (executor.getGrade() > getRequiredGradeToExecute())
		throw GradeTooLowException();
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
