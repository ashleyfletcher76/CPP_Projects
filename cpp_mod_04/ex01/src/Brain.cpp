/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 07:06:39 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/04 15:02:22 by asfletch         ###   ########.fr       */
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

void Brain::SetIdeas(std::string str)
{
	for (int i = 0; i < 100; i++)
		ideas[i] = str;
}

std::string Brain::GetIdeas( void )
{
	return *ideas;
}

void Brain::PrintIdeas(unsigned int NumIdeas)
{
	for (unsigned int i = 0; i < NumIdeas; i++)
		std::cout << ideas[i] << std::endl;
}
