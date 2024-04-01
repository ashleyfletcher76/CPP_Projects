/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 09:59:52 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/01 09:30:30 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//-----------Constructors etc..----------//

Fixed::Fixed() : _FixedValue(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& CopyConstruct) : _FixedValue(CopyConstruct._FixedValue)
{
	//std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed& CopyAssignment)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &CopyAssignment)
		this->setRawBits(CopyAssignment.getRawBits());
	return (*this);
}

Fixed::Fixed(const int IntToConvert)
{
	//std::cout << "Int constructor called" << std::endl;
	// Converts the fixed point value to an integer. Num * 256(2^8)
	_FixedValue = IntToConvert << _FractionalBit;
}

Fixed::Fixed(const float FloatToConvert)
{
	//std::cout << "Float constructor called" << std::endl;
	// Converts the fixed-point value to a FP number. Num * 256(2^8)
	_FixedValue = roundf(FloatToConvert * (1 << _FractionalBit));
}

std::ostream& operator<<(std::ostream& ostream, const Fixed& num)
{
	ostream << num.toFloat();
	return (ostream);
}

int Fixed::getRawBits( void ) const
{
	return (this->_FixedValue);
}

void Fixed::setRawBits(int const raw)
{
	this->_FixedValue = raw;
}

//---------Min/Max-----------//
// static member functions belong to the class not the objects themselves

Fixed &Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b) ? a : b;
}

//--------Maths functions-----------//
//Fixed(..) returns a new object

Fixed Fixed::operator+(const Fixed& other) const
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed& other) const
{
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed& other) const
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed& other) const
{
	return (Fixed(this->toFloat() / other.toFloat()));
}

//-------Comparison--------//

bool Fixed::operator>(const Fixed& other) const
{
	return (toFloat() > other.toFloat());
}

bool Fixed::operator<(const Fixed& other) const
{
	return (toFloat() < other.toFloat());
}

bool Fixed::operator>=(const Fixed& other) const
{
	return (toFloat() >= other.toFloat());
}

bool Fixed::operator<=(const Fixed& other) const
{
	return (toFloat() <= other.toFloat());
}

bool Fixed::operator==(const Fixed& other) const
{
	return (toFloat() == other.toFloat());
}

bool Fixed::operator!=(const Fixed& other) const
{
	return (toFloat() != other.toFloat());
}

//------Incremement/Decrement-------//

Fixed &Fixed::operator++( void )
{
	++_FixedValue;
	return (*this); //reference to modified object;
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this); //Create a copy of object
	++(*this); //
	return (temp); // original value --> next time equals new value
}

Fixed &Fixed::operator--( void )
{
	--_FixedValue;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	--(*this);
	return (temp);
}
