/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 09:59:52 by asfletch          #+#    #+#             */
/*   Updated: 2024/03/30 10:36:51 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : FixedValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& CopyConstruct) : FixedValue(CopyConstruct.FixedValue)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed& CopyAssignment)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &CopyAssignment)
		this->setRawBits(CopyAssignment.getRawBits());
	return (*this);
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->FixedValue);
}

void Fixed::setRawBits(int const raw)
{
	this->FixedValue = raw;
}
