/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:44:51 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/21 12:49:51 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

//------------Orthodox/constructors-----------//

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) :
	AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) :
	AForm(other), _target(other._target)
{
	//std::cout << "RobotomyRequestForm's copy constructor initialized" <<std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		//std::cout << "RobotomyRequestForm's copy assignment initialized" << std::endl;
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

//------------Main Functions-------------//

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!checkSigned())
		throw FormNotSigned();
	if (executor.getGrade() > getRequiredGradeToExecute())
		throw GradeTooLowException();
	std::cout << "Yes this is a drilling sound." << std::endl;
	if (rand() % 2 == 0)
		std::cout << _target << "has been robotomized!" << std::endl;
	else
		std::cout << _target << "did not get robotomized....unfortunately." << std::endl;
}
