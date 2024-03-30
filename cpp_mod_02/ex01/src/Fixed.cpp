/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 09:59:52 by asfletch          #+#    #+#             */
/*   Updated: 2024/03/30 11:53:38 by asfletch         ###   ########.fr       */
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

Fixed::Fixed(const int IntToConvert) : FixedValue(IntToConvert << Fixed::FractionalBit)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float FloatToConvert) : FixedValue(roundf(FloatToConvert * (1 << Fixed::FractionalBit)))
{
	std::cout << "Float constructor called" << std::endl;
}

int Fixed::toInt(void) const
{
	return (FixedValue >> FractionalBit);
}

float Fixed::toFloat( void ) const
{
	return ((float)FixedValue / (float)(1 << FractionalBit));
}

std::ostream& operator<<(std::ostream& os, const Fixed& num)
{
	os << num.toFloat();
	return (os);
}

int Fixed::getRawBits( void ) const
{
	return (this->FixedValue);
}

void Fixed::setRawBits(int const raw)
{
	this->FixedValue = raw;
}
