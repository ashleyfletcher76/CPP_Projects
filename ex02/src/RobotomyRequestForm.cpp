/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:44:51 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/19 14:52:29 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
{
	//std::cout << "RobotomyRequestForm default constructor initialized." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	//std::cout << "RobotomyRequestForm deconstructor initialized." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) :
	_name(other._name), _grade(other._grade)
{
	//std::cout << "RobotomyRequestForm's copy constructor initialized" <<std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		//std::cout << "RobotomyRequestForm's copy assignment initialized" << std::endl;
		_grade = other._grade;
	}
	return (*this);
}
