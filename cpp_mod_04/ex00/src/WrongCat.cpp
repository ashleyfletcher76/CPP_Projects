/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:51:20 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/03 17:08:53 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << LIGHT_BLUE << "WrongCat's constructor has been initialized." << RESET << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << RED << "WrongCat's deconstructor has been initialized." << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	std::cout << MAGENTA << "WrongCat's copy constructor Initialized"
		<< RESET <<std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	if (this != &other)
	{
		std::cout << MAGENTA << "WrongCat's copy assignment initialized"
			<< RESET << std::endl;
	}
	return (*this);
}

void WrongCat::makeSound( void ) const
{
	std::cout << YELLOW << "Wrong cat" << RESET << std::endl;
}
