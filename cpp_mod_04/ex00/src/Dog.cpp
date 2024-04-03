/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:51:03 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/03 13:57:38 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
}

Dog::~Dog()
{
}

Dog::Dog(const Dog& other)
{
	std::cout << MAGENTA << "Dog's copy constructor Initialized"
		<< RESET <<std::endl;
	_name = other._name;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		std::cout << MAGENTA << "Dog's copy assignment initialized"
			<< RESET << std::endl;
	}
	return (*this);
}
