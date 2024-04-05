/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:50:31 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/05 13:23:48 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	brain = new Brain();
	std::cout << LIGHT_BLUE << "Cat's constructor has been initialized." << RESET << std::endl;
}

Cat::~Cat()
{
	std::cout << RED << "Cat's deconstructor has been initialized." << RESET << std::endl;
	delete brain;
}

Cat::Cat(const Cat& other) : AAnimal(other), brain(new Brain(*other.brain))
{
	std::cout << MAGENTA << "Cat's copy constructor Initialized"
		<< RESET <<std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		std::cout << MAGENTA << "Cat's copy assignment initialized"
			<< RESET << std::endl;
		AAnimal::operator=(other);
		Brain* NewBrain = new Brain(*other.brain);
		delete brain;
		brain = NewBrain;
	}
	return (*this);
}

void Cat::makeSound( void ) const
{
	std::cout << YELLOW << "The cat goes meeeeeeeeow!" << RESET << std::endl;
}

Brain* Cat::GetBrain( void )
{
	return (brain);
}

void Cat::SetIdeas(const std::string& idea) const
{
	for (unsigned int i = 0; i < 100; i++)
		brain->SetIdeas(idea, i);
}

void Cat::PrintIdeas(unsigned int NumIdeas)
{
	brain->PrintIdeas(NumIdeas);
}
