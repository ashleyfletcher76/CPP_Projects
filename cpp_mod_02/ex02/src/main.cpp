/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 10:00:18 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/01 09:30:04 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

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

// Original a = 0
// precrement a = 0.00390625
// Pre Modified a = 0.00390625
// Postcrement a = 0.00390625
// Post Modified a = 0.0078125
// b = 10.1016
// e = 2.52734
// Max of a and b = 10.1016
// Min of c and d = 5

