/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:51:20 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/03 13:57:24 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
}

WrongCat::~WrongCat()
{
}

WrongCat::WrongCat(const WrongCat& other)
{
	std::cout << MAGENTA << "WrongCat's copy constructor Initialized"
		<< RESET <<std::endl;
	_name = other._name;
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
