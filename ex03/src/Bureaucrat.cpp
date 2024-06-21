/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 09:30:51 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/21 11:54:15 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//------------Orthodox/constructors-----------//

Bureaucrat::Bureaucrat() : _name("Default Mr Man"), _grade(150) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
	//std::cout << "Bureaucrat's copy constructor initialized" <<std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		//std::cout << "Bureaucrat's copy assignment initialized" << std::endl;
		_name = other._name;
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
	if (_grade <= 1)
		throw GradeTooLowException();
	--_grade;
}

void	Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
		throw GradeTooHighException();
	++_grade;
}

void	Bureaucrat::signForm(AForm &form)
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

void	Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << _name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}
