/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:29:21 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/18 14:34:44 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Default Mr Man"), _sign(false), _grade(125), _requiredGrade(150)
{
	std::cout << "Form default constructor initialized." << std::endl;
}

Form::~Form()
{
	std::cout << "Form deconstructor initialized." << std::endl;
}

Form::Form(const Form& other) : _name(other._name), _sign(other._sign), _grade(other._grade), _requiredGrade(other._requiredGrade)
{
	std::cout << "Form's copy constructor Initialized" <<std::endl;
}

Form::Form(const std::string &name, bool sign, int grade, int requiredGrade) : _name(name), _sign(sign), _grade(grade), _requiredGrade(requiredGrade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
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

std::ostream &operator<<(std::ostream &out, Form const &form)
{
	out << form.getName() << ", bureaucrat grade " << form.getGrade() << ".";
	return (out);
}
