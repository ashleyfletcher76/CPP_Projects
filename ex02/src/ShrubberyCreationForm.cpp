/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:45:06 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/20 10:25:07 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

//------------Orthodox/constructors-----------//

ShrubberyCreationForm::ShrubberyCreationForm()
{
	//std::cout << "ShrubberyCreationForm default constructor initialized." << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	//std::cout << "ShrubberyCreationForm deconstructor initialized." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) :
	_name(other._name), _grade(other._grade)
{
	//std::cout << "ShrubberyCreationForm's copy constructor initialized" <<std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		//std::cout << "ShrubberyCreationForm's copy assignment initialized" << std::endl;
		_grade = other._grade;
	}
	return (*this);
}

//------------Main Functions-------------//
