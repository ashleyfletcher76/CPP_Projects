/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 13:03:08 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/06 13:14:04 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() {}

Ice::~Ice() {}

Ice::Ice(const Ice& other) {}

Ice& Ice::operator=(const Ice& other)
{
	if (this != &other)
	{
		(void)other;
	}
	return (*this);
}

Ice::Ice clone()
{
	return (new Ice(*this));
}
