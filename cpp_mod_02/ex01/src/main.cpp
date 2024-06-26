/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 10:00:18 by asfletch          #+#    #+#             */
/*   Updated: 2024/03/31 14:06:51 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(const int IntToConvert)
{
	std::cout << "Int constructor called" << std::endl;
	// Converts the fixed point value to an integer. Num * 256(2^8)
	_FixedValue = IntToConvert << _FractionalBit;
}

Fixed::Fixed(const float FloatToConvert)
{
	std::cout << "Float constructor called" << std::endl;
	// Converts the fixed-point value to a FP number. Num * 256(2^8)
	_FixedValue = roundf(FloatToConvert * (1 << _FractionalBit));
}

int Fixed::toInt(void) const
{
	// Shifts to the right by 8 bits, i.e. dividing by 2^8
	return (_FixedValue >> _FractionalBit);
}

float Fixed::toFloat( void ) const
{
	// Division by 2^8 i.e. shifted by _FractionalBit(8), converts fixed point number to FP
	return ((float)_FixedValue / (float)(1 << _FractionalBit));
}

int main( void )
{
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	a = Fixed( 1234.4321f );
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return 0;
}

// int main( void )
// {
// 	Fixed a;
// 	Fixed const b( 5 );
// 	Fixed const c( 5.73f);
// 	Fixed const d( b );
// 	a = Fixed( 1234.4321f );
// 	std::cout << "a is " << a << std::endl;
// 	std::cout << "b is " << b << std::endl;
// 	std::cout << "c is " << c << std::endl;
// 	std::cout << "d is " << d << std::endl;
// 	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
// 	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
// 	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
// 	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
// 	std::cout << "a is " << a.toFloat() << " as float" << std::endl;
// 	std::cout << "b is " << b.toFloat() << " as float" << std::endl;
// 	std::cout << "c is " << c.toFloat() << " as float" << std::endl;
// 	std::cout << "d is " << d.toFloat() << " as float" << std::endl;
// 	return 0;
// }
