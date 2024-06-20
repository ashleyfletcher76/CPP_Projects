/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:44:51 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/20 16:40:31 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

//------------Orthodox/constructors-----------//

RobotomyRequestForm::RobotomyRequestForm() :
	AForm("RobotomyRequestForm", 72, 45), _target("Default Robo") {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : _target(other._target)
{
	//std::cout << "RobotomyRequestForm's copy constructor initialized" <<std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		//std::cout << "RobotomyRequestForm's copy assignment initialized" << std::endl;
		_target = other._target;
	}
	return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) :
	AForm("RobotomyRequestForm", 72, 45), _target(target) {}

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
