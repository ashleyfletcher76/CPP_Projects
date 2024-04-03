/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:50:31 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/03 13:58:03 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
}

Cat::~Cat()
{
}

Cat::Cat(const Cat& other)
{
	std::cout << MAGENTA << "Cat's copy constructor Initialized"
		<< RESET <<std::endl;
	_name = other._name;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		std::cout << MAGENTA << "Cat's copy assignment initialized"
			<< RESET << std::endl;
	}
	return (*this);
}
