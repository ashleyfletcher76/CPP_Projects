/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BureaucratUtils.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 10:21:10 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/20 10:22:19 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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
	return ("grade is too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("grade is too low!");
}

std::ostream &operator<<(std::ostream& out, Bureaucrat const &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (out);
}
