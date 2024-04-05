/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 07:06:39 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/05 12:08:49 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << LIGHT_BLUE << "Brain's constructor has been initialized." << RESET << std::endl;
}

Brain::~Brain()
{
	std::cout << RED << "Brain's deconstructor has been initialized." << RESET << std::endl;
}

Brain::Brain(const Brain& other)
{
	std::cout << MAGENTA << "Brain's copy constructor initialized."
		<< RESET <<std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = other.ideas[i];
}

Brain& Brain::operator=(const Brain& other)
{
	if (this != &other)
	{
		std::cout << MAGENTA << "Brain's copy assignment initialized"
			<< RESET << std::endl;
		for (int i = 0; i < 100; i++)
			ideas[i] = other.ideas[i];
	}
	return (*this);
}

void Brain::SetIdeas(std::string str, unsigned int i)
{
	//std::cout << "Brain::SetIdeas called" << std::endl;
	if (i < 100)
		ideas[i] = str;
	else
		std::cerr << "Index error" << std::endl;
}

std::string Brain::GetIdeas( void )
{
	//std::cout << "Brain::GetIdea called" << std::endl;
	return (*ideas);
}

void Brain::PrintIdeas(unsigned int NumIdeas)
{
	//std::cout << "Brain::PrintIdeas called" << std::endl;
	for (unsigned int i = 0; i < NumIdeas; i++)
		std::cout << ideas[i] << std::endl;
}
