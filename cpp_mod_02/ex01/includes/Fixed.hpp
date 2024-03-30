/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 09:59:02 by asfletch          #+#    #+#             */
/*   Updated: 2024/03/30 12:06:19 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
	private:
		int	_FixedValue;
		static const int _FractionalBit = 8;

	public:
		Fixed(); //default
		Fixed(const Fixed& CopyConstruct);
		Fixed&operator=(const Fixed& CopyAssignment);
		~Fixed();

		Fixed(const int IntToConvert);
		Fixed(const float FloatToConvert);
		float toFloat( void ) const;
		int toInt( void ) const;

		int getRawBits( void ) const;
		void setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream& os, const Fixed& num);

#endif
