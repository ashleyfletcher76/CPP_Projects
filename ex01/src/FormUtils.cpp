/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FormUtils.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:04:49 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/21 12:05:52 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

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
