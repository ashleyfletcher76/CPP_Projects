/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 09:59:02 by asfletch          #+#    #+#             */
/*   Updated: 2024/03/30 10:24:10 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
	private:
		int	FixedValue;
		static const int FractionalBit = 8;

	public:
		Fixed();
		Fixed(const Fixed& CopyConstruct);
		Fixed&operator=(const Fixed& CopyAssignment);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits(int const raw);
};

#endif
