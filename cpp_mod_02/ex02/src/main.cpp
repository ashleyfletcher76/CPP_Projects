/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 10:00:18 by asfletch          #+#    #+#             */
/*   Updated: 2024/03/31 16:02:14 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

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
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed c(5);
	Fixed d(10);
	Fixed const e( Fixed( 5.05f ) / Fixed( 2 ) );
	std::cout << "Original a = " << a << std::endl;
	std::cout << "precrement a = " << ++a << std::endl;
	std::cout << "Pre Modified a = " << a << std::endl;
	std::cout << "Postcrement a = " << a++ << std::endl;
	std::cout << "Post Modified a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "e = " << e << std::endl;
	std::cout << "Max of a and b = " << Fixed::max( a, b ) << std::endl;
	std::cout << "Min of c and d = " << Fixed::min( c, d ) << std::endl;
	return 0;
}

// int main( void )
// {
// 	Fixed a;
// 	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << b << std::endl;
// 	std::cout << Fixed::max( a, b ) << std::endl;
// 	return 0;
// }


