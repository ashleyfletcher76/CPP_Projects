/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AFormUtils.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 10:19:06 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/20 11:19:51 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

void	AForm::setSignature()
{
	_signature = true;
}

std::string AForm::getName() const
{
	return(_name);
}

int AForm::getRequiredGradeToSign() const
{
	return(_requiredGradeMin);
}

int AForm::getRequiredGradeToExecute() const
{
	return(_executeGrade);
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("grade is too high!");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("grade is too low!");
}

const char* AForm::FormNotSigned::what() const throw()
{
	return ("is not signed!");
}

std::ostream &operator<<(std::ostream &out, AForm const &form)
{
	out << form.getName() << ", form's required grade is " << form.getRequiredGradeToSign() << ".";
	return (out);
}
