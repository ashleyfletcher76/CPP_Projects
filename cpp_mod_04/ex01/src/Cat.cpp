/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:50:31 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/04 11:41:44 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), brains(new Brain())
{
	// type = "Cat";
	// brain = new Brain();
	std::cout << LIGHT_BLUE << "Cat's constructor has been initialized." << RESET << std::endl;
}

Cat::~Cat()
{
	std::cout << RED << "Cat's deconstructor has been initialized." << RESET << std::endl;
	delete brains;
}

Cat::Cat(const Cat& other) : Animal(other)
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
		delete brains;
		brains = new Brain(*other.brains);
	}
	return (*this);
}

// Cat::Cat(Brain& BrainInput) : brain(new Brain(BrainInput))
// {
// 	type = "Cat";
// 	std::cout << LIGHT_BLUE << "Cat's Brain constructor has been initialized." << RESET << std::endl;
// }

void Cat::makeSound( void ) const
{
	std::cout << YELLOW << "The cat goes meeeeeeeeow!" << RESET << std::endl;
}

Brain* Cat::GetIdeas( void )
{
	return (brains);
}

void Cat::SetIdeas(const std::string& idea) const
{
	brains->SetIdeas(idea);
}
