/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:29:21 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/18 16:35:04 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Default Mr Man"), _sign(false), _requiredGradeMin(150), _executeGrade(125)
{
	std::cout << "Form default constructor initialized." << std::endl;
}

Form::~Form()
{
	std::cout << "Form deconstructor initialized." << std::endl;
}

Form::Form(const Form& other) : _name(other._name), _sign(other._sign), _requiredGradeMin(other._requiredGradeMin), _executeGrade(other._executeGrade)
{
	std::cout << "Form's copy constructor Initialized" <<std::endl;
}

Form::Form(const std::string &name, int requiredGradeMin, int executeGrade) : _name(name),
	_sign(false), _requiredGradeMin(requiredGradeMin), _executeGrade(executeGrade)
{
	if (_requiredGradeMin < 1 || _executeGrade < 1)
		throw GradeTooHighException();
	if (_requiredGradeMin > 150 || _executeGrade > 150)
		throw GradeTooLowException();
	std::cout << "Form's constructor has been initialized." << std::endl;
}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
	{
		std::cout << "Form's copy assignment initialized" << std::endl;
		_sign = other._sign;
	}
	return (*this);
}

void	Form::beSigned(Bureaucrat& bureaucrat)
{
	if (_sign)
		std::cout << bureaucrat.getName() << "'s form is already signed!" << std::endl;
	else
	{
		std::cout << bureaucrat.getName() << "'s form can be signed!" << std::endl;
		signForm();
	}
	if (bureaucrat.getGrade() > _requiredGradeMin)
		throw GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

void	Form::signForm()
{
	_sign = true;
}

std::string Form::getName() const
{
	return(_name);
}

int Form::getGrade() const
{
	return(_requiredGradeMin);
}

int Form::getExecute() const
{
	return(_executeGrade);
}

std::ostream &operator<<(std::ostream &out, Form const &form)
{
	out << form.getName() << ", form's required grade is " << form.getGrade() << ".";
	return (out);
}
