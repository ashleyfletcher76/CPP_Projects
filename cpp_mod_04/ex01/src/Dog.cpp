/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:51:03 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/05 11:06:13 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	brains = new Brain();
	std::cout << LIGHT_BLUE << "Dog's constructor has been initialized." << RESET << std::endl;
}

Dog::~Dog()
{
	std::cout << RED << "Dog's deconstructor has been initialized." << RESET << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other), brains(new Brain(*other.brains))
{
	std::cout << MAGENTA << "Dog's copy constructor initialized."
		<< RESET <<std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		std::cout << MAGENTA << "Dog's copy assignment initialized"
			<< RESET << std::endl;
		Animal::operator=(other);
		Brain* NewBrain = new Brain(*other.brains);
		delete brains;
		brains = NewBrain;
	}
	return (*this);
}

void Dog::makeSound( void ) const
{
	std::cout << YELLOW << "The dog goes woof woof!" << RESET << std::endl;
}

Brain* Dog::GetBrain( void )
{
	return (brains);
}

void Dog::SetIdea(const std::string& idea) const
{
	for (unsigned int i = 0; i < 100; i++)
		brains->SetIdeas(idea);
}

void Dog::PrintIdeas(unsigned int NumIdeas)
{
	brains->PrintIdeas(NumIdeas);
}
