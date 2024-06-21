/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:45:06 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/21 12:50:22 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

//------------Orthodox/constructors-----------//

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) :
	AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	//std::cout << "ShrubberyCreationForm deconstructor initialized." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) :
	AForm(other), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		//std::cout << "ShrubberyCreationForm's copy assignment initialized" << std::endl;
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

//------------Main Functions-------------//

# define TREE     "      $      \n"\
                  "     $$$     \n"\
                  "    $$$$$    \n"\
                  "   $$$$$$$   \n"\
                  " $$$$$$$$$$$ \n"\
                  "$$$$$$$$$$$$$\n"\
                  "     |||     \n"\
                  "     |||     \n"\

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!checkSigned())
		throw FormNotSigned();
	if (executor.getGrade() > getRequiredGradeToExecute())
		throw GradeTooLowException();
	std::ofstream ofs((_target + "_shrubbery").c_str());
	if (!ofs)
	{
		std::cerr << "Error opening " << _target << "_shrubbery file." << std::endl;
		return ;
	}
	ofs << TREE << std::endl;
	ofs.close();
}
