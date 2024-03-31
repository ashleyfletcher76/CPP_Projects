/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 09:59:52 by asfletch          #+#    #+#             */
/*   Updated: 2024/03/31 12:12:45 by asfletch         ###   ########.fr       */
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
