/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:49:53 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/05 13:33:18 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : type("Big Giant Bear")
{
	std::cout << LIGHT_BLUE << "AAnimal's constructor has been initialized." << RESET << std::endl;
}

AAnimal::AAnimal(std::string name) : type(name)
{
	std::cout << LIGHT_BLUE << "AAnimal's constructor has been initialized." << RESET << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << RED << "AAnimal's deconstructor has been initialized." << RESET << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : type(other.type)
{
	std::cout << MAGENTA << "AAnimal's copy constructor Initialized"
		<< RESET <<std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other)
{
	if (this != &other)
	{
		std::cout << MAGENTA << "AAnimal's copy assignment initialized"
			<< RESET << std::endl;
		type = other.type;
	}
	return (*this);
}

std::string AAnimal::getType( void ) const
{
	return(type);
}

void AAnimal::makeSound( void ) const
{
	std::cout << YELLOW << "The big giant bear goes mooooooooo!" << RESET << std::endl;
}

Brain* AAnimal::GetBrain( void )
{
	std::cout << "AAnimal::GetBrain called" << std::endl;
	return (NULL);
}

void AAnimal::SetIdeas(const std::string& idea) const
{
	std::cout << "AAnimal::SetIdeas called" << std::endl;
	(void)idea;
	return ;
}

void AAnimal::PrintIdeas(unsigned int NumIdeas)
{
	std::cout << "AAnimal::PrintIdeas called" << std::endl;
	(void)NumIdeas;
}
