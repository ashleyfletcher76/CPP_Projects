/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:51:16 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/04 06:38:09 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Wrong animal")
{
	std::cout << LIGHT_BLUE << "WrongAnimal's constructor has been initialized." << RESET << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << RED << "WrongAnimal's deconstructor has been initialized." << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	std::cout << MAGENTA << "WrongAnimal's copy constructor Initialized" <<  RESET << std::endl;
	type = other.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this != &other)
	{
		std::cout << MAGENTA << "WrongAnimal's copy assignment initialized"
			<< RESET << std::endl;
	}
	return (*this);
}

void WrongAnimal::makeSound( void ) const
{
	std::cout << YELLOW << "Looooool its being outputted (WrongAnimal)" << RESET << std::endl;
}
