/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:50:31 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/03 17:08:45 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	std::cout << LIGHT_BLUE << "Cat's constructor has been initialized." << RESET << std::endl;
}

Cat::~Cat()
{
	std::cout << RED << "Cat's deconstructor has been initialized." << RESET << std::endl;
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
	}
	return (*this);
}

void Cat::makeSound( void ) const
{
	std::cout << YELLOW << "The cat goes meeeeeeeeow!" << RESET << std::endl;
}
