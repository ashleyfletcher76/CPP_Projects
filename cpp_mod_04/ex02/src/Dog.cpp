/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:51:03 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/05 13:23:54 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	brain = new Brain();
	std::cout << LIGHT_BLUE << "Dog's constructor has been initialized." << RESET << std::endl;
}

Dog::~Dog()
{
	std::cout << RED << "Dog's deconstructor has been initialized." << RESET << std::endl;
	delete brain;
}

Dog::Dog(const Dog& other) : AAnimal(other), brain(new Brain(*other.brain))
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
		AAnimal::operator=(other);
		Brain* NewBrain = new Brain(*other.brain);
		delete brain;
		brain = NewBrain;
	}
	return (*this);
}

void Dog::makeSound( void ) const
{
	std::cout << YELLOW << "The dog goes woof woof!" << RESET << std::endl;
}

Brain* Dog::GetBrain( void )
{
	//std::cout << "Dog::GetBrain called" << std::endl;
	return (brain);
}

void Dog::SetIdeas(const std::string& idea) const
{
	//std::cout << "Dog::SetIdea called" << std::endl;
	for (unsigned int i = 0; i < 100; i++)
		brain->SetIdeas(idea, i);
}

void Dog::PrintIdeas(unsigned int NumIdeas)
{
	//std::cout << "Dog::PrintIdeas called" << std::endl;
	brain->PrintIdeas(NumIdeas);
}
