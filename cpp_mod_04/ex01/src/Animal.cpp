/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:49:53 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/05 12:29:02 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Big Giant Bear")
{
	std::cout << LIGHT_BLUE << "Animal's constructor has been initialized." << RESET << std::endl;
}

Animal::Animal(std::string name) : type(name)
{
	std::cout << LIGHT_BLUE << "Animal's constructor has been initialized." << RESET << std::endl;
}

Animal::~Animal()
{
	std::cout << RED << "Animal's deconstructor has been initialized." << RESET << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type)
{
	std::cout << MAGENTA << "Animal's copy constructor Initialized"
		<< RESET <<std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
	if (this != &other)
	{
		std::cout << MAGENTA << "Animal's copy assignment initialized"
			<< RESET << std::endl;
		type = other.type;
	}
	return (*this);
}

std::string Animal::getType( void ) const
{
	return(type);
}

void Animal::makeSound( void ) const
{
	std::cout << YELLOW << "The big giant bear goes mooooooooo!" << RESET << std::endl;
}

Brain* Animal::GetBrain( void )
{
	std::cout << "Animal::GetBrain called" << std::endl;
	return (NULL);
}

void Animal::SetIdeas(const std::string& idea) const
{
	std::cout << "Animal::SetIdeas called" << std::endl;
	(void)idea;
	return ;
}

void Animal::PrintIdeas(unsigned int NumIdeas)
{
	std::cout << "Animal::PrintIdeas called" << std::endl;
	(void)NumIdeas;
}
