/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:44:08 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/19 14:52:37 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
{
	//std::cout << "PresidentialPardonForm default constructor initialized." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	//std::cout << "PresidentialPardonForm deconstructor initialized." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) :
	_name(other._name), _grade(other._grade)
{
	//std::cout << "PresidentialPardonForm's copy constructor initialized" <<std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		//std::cout << "PresidentialPardonForm's copy assignment initialized" << std::endl;
		_grade = other._grade;
	}
	return (*this);
}
