/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 09:59:52 by asfletch          #+#    #+#             */
/*   Updated: 2024/03/30 12:11:22 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _FixedValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& CopyConstruct) : _FixedValue(CopyConstruct._FixedValue)
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

Fixed::Fixed(const int IntToConvert)
{
	std::cout << "Int constructor called" << std::endl;
	_FixedValue = IntToConvert << _FractionalBit;
}

Fixed::Fixed(const float FloatToConvert)
{
	std::cout << "Float constructor called" << std::endl;
	_FixedValue = roundf(FloatToConvert * (1 << _FractionalBit));
}

int Fixed::toInt(void) const
{
	return (_FixedValue >> _FractionalBit);
}

float Fixed::toFloat( void ) const
{
	return ((float)_FixedValue / (float)(1 << _FractionalBit));
}

std::ostream& operator<<(std::ostream& os, const Fixed& num)
{
	os << num.toFloat();
	return (os);
}

int Fixed::getRawBits( void ) const
{
	return (this->_FixedValue);
}

void Fixed::setRawBits(int const raw)
{
	this->_FixedValue = raw;
}
