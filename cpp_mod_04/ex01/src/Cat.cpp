/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:50:31 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/04 14:39:13 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	type = "Cat";
	brains = new Brain();
	std::cout << LIGHT_BLUE << "Cat's constructor has been initialized." << RESET << std::endl;
}

Cat::~Cat()
{
	std::cout << RED << "Cat's deconstructor has been initialized." << RESET << std::endl;
	delete brains;
}

Cat::Cat(const Cat& other) : Animal(other), brains(new Brain(*other.brains))
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
		Animal::operator=(other);
		Brain* NewBrain = new Brain(*other.brains);
		delete brains;
		brains = NewBrain;
	}
	return (*this);
}

void Cat::makeSound( void ) const
{
	std::cout << YELLOW << "The cat goes meeeeeeeeow!" << RESET << std::endl;
}

Brain* Cat::GetBrainAddress( void )
{
	return (brains);
}

void Cat::SetIdea(const std::string& idea) const
{
	for (unsigned int i = 0; i < 100; i++)
		brains->SetIdeas(idea);
}

void Cat::PrintIdeas(unsigned int NumIdeas)
{
	brains->PrintIdeas(NumIdeas);
}
