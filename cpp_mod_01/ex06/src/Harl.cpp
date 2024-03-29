/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 07:20:36 by asfletch          #+#    #+#             */
/*   Updated: 2024/03/29 07:20:38 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::~Harl() {}

void Harl::debug( void )
{
	std::cout << "Chicken nuggets." << std::endl;
}

void Harl::info( void )
{
	std::cout << "Are the best." << std::endl;
}

void Harl::warning( void )
{
	std::cout << "But you can't always have them." << std::endl;
}

void Harl::error( void )
{
	std::cout << "Otherwise you'll have a big tum tum." << std::endl;
}
