/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:51:16 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/03 13:57:07 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
}

WrongAnimal::~WrongAnimal()
{
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	std::cout << MAGENTA << "WrongAnimal's copy constructor Initialized"
		<< RESET <<std::endl;
	_name = other._name;
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
