/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:29:21 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/20 12:27:03 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Default Mr Man"), _signature(false), _requiredGradeMin(150), _executeGrade(125)
{
	//std::cout << "Form default constructor initialized." << std::endl;
}

Form::~Form()
{
	//std::cout << "Form deconstructor initialized." << std::endl;
}

Form::Form(const Form& other) : _name(other._name), _signature(other._signature),
	_requiredGradeMin(other._requiredGradeMin), _executeGrade(other._executeGrade)
{
	//std::cout << "Form's copy constructor Initialized" <<std::endl;
}

Form::Form(const std::string &name, int requiredGradeMin, int executeGrade) : _name(name),
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

Form& Form::operator=(const Form& other)
{
	if (this != &other)
	{
		//std::cout << "Form's copy assignment initialized" << std::endl;
		_signature = other._signature;
	}
	return (*this);
}

void	Form::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _requiredGradeMin)
	{
		std::cout << bureaucrat.getName() << "'s";
		throw GradeTooLowException();
	}
	if (_signature)
		std::cout << bureaucrat.getName() << " cant sign " << _name << "because it is already signed!"
			<< std::endl;
	else
	{
		std::cout << bureaucrat.getName() << " signed the " << _name << std::endl;
		setSignature();
	}
}

bool	Form::checkSigned() const
{
	return (_signature);
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("grade is too high!");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("grade is too low!");
}

void	Form::setSignature()
{
	_signature = true;
}

std::string Form::getName() const
{
	return(_name);
}

int Form::getRequiredGradeToSign() const
{
	return(_requiredGradeMin);
}

int Form::getRequiredGradeToExecute() const
{
	return(_executeGrade);
}

std::ostream &operator<<(std::ostream &out, Form const &form)
{
	out << form.getName() << ", form's required grade to sign is " << form.getRequiredGradeToSign() << ".\n"
		<< "The required grade to execute is " << form.getRequiredGradeToExecute() << ".\n"
		<< "The signed status is - "
		<< (form.checkSigned() ? "Yes" : "No") << "." << std::endl;
	return (out);
}
