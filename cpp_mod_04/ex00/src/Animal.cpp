/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:49:53 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/03 13:58:34 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Animal.hpp>

Animal::Animal()
{
}

Animal::~Animal()
{
}

Animal::Animal(const Animal& other)
{
	std::cout << MAGENTA << "Animal's copy constructor Initialized"
		<< RESET <<std::endl;
	_name = other._name;
}

Animal& Animal::operator=(const Animal& other)
{
	if (this != &other)
	{
		std::cout << MAGENTA << "Animal's copy assignment initialized"
			<< RESET << std::endl;
	}
	return (*this);
}
