/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 09:30:51 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/17 17:18:43 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default Mr Man"), _grade(150)
{
	std::cout << "Bureaucrat's default constructor has been initialized." << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat's deconstructor has been initialized." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
	std::cout << "Bureaucrat's copy constructor Initialized" <<std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		std::cout << "Bureaucrat's copy assignment initialized" << std::endl;
		_grade = other._grade;
	}
	return (*this);
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooLowException();
	if (grade > 150)
		throw GradeTooHighException();
	std::cout << "Bureaucrat's constructor has been initialized." << std::endl;
}

std::string Bureaucrat::getName() const
{
	return(_name);
}

int Bureaucrat::getGrade() const
{
	return(_grade);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

void	Bureaucrat::incrementGrade()
{
	//std::cout << "Increment grade has been called." << std::endl;
	if (_grade >= 150)
		throw GradeTooHighException();
	++_grade;
}

void	Bureaucrat::decrementGrade()
{
	//std::cout << "Decrement grade has been called." << std::endl;
	if (_grade <= 1)
		throw GradeTooLowException();
	--_grade;
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (out);
}
