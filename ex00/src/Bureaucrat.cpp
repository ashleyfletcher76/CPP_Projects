/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 09:30:51 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/17 15:27:23 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	std::cout << "Bureaucrat's constructor has been initialized." << std::endl;
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

const std::string Bureaucrat::getName( void ) const
{
	return(this->_name);
}

const int Bureaucrat::getGrade( void ) const
{
	return(this->_grade);
}
