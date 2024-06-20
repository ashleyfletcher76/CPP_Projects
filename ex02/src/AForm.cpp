/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:29:21 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/20 11:28:15 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

//------------Orthodox/constructors-----------//

AForm::AForm() : _name("Default Mr Man"), _signature(false), _requiredGradeMin(150), _executeGrade(125)
{
	//std::cout << "Form default constructor initialized." << std::endl;
}

AForm::~AForm()
{
	//std::cout << "Form deconstructor initialized." << std::endl;
}

AForm::AForm(const AForm& other) : _name(other._name), _signature(other._signature),
	_requiredGradeMin(other._requiredGradeMin), _executeGrade(other._executeGrade)
{
	//std::cout << "Form's copy constructor initialized" <<std::endl;
}

AForm::AForm(const std::string &name, int requiredGradeMin, int executeGrade) : _name(name),
	_signature(false), _requiredGradeMin(requiredGradeMin), _executeGrade(executeGrade)
{
	if (_requiredGradeMin < 1)
	{
		std::cout << "Required ";
		throw GradeTooHighException();
	}
	if (_executeGrade < 1)
	{
		std::cout << "Execute  ";
		throw GradeTooHighException();
	}
	if (_requiredGradeMin > 150)
	{
		std::cout << "Required ";
		throw GradeTooLowException();
	}
	if (_executeGrade > 150)
	{
		std::cout << "Execute ";
		throw GradeTooLowException();
	}
	//std::cout << "Form's constructor has been initialized." << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		//std::cout << "Form's copy assignment initialized" << std::endl;
		_signature = other._signature;
	}
	return (*this);
}

//------------Main Functions-------------//

void	AForm::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _requiredGradeMin)
	{
		std::cout << bureaucrat.getName() << "'s";
		throw GradeTooLowException();
	}
	if (_signature)
		std::cout << bureaucrat.getName() << " cant sign " << _name
			<< "because it is already signed!" << std::endl;
	else
	{
		std::cout << bureaucrat.getName() << " signed the " << _name << std::endl;
		setSignature();
	}
}

void	AForm::checkSigned()
{
	return (_signature);
}
