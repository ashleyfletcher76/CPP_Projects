/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 09:30:51 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/20 10:23:24 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//------------Orthodox/constructors-----------//

Bureaucrat::Bureaucrat() : _name("Default Mr Man"), _grade(150)
{
	//std::cout << "Bureaucrat's default constructor has been initialized." << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	//std::cout << "Bureaucrat's deconstructor has been initialized." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
	//std::cout << "Bureaucrat's copy constructor initialized" <<std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		//std::cout << "Bureaucrat's copy assignment initialized" << std::endl;
		_grade = other._grade;
	}
	return (*this);
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
	{
		std::cout << _name << "'s ";
		throw GradeTooHighException();
	}
	if (grade > 150)
	{
		std::cout << _name << "'s ";
		throw GradeTooLowException();
	}
	//std::cout << "Bureaucrat's constructor has been initialized." << std::endl;
}

//------------Main Functions-------------//

void	Bureaucrat::incrementGrade()
{
	//std::cout << "Increment grade has been called." << std::endl;
	if (_grade >= 150)
		throw GradeTooLowException();
	++_grade;
}

void	Bureaucrat::decrementGrade()
{
	//std::cout << "Decrement grade has been called." << std::endl;
	if (_grade <= 1)
		throw GradeTooHighException();
	--_grade;
}

void	Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
