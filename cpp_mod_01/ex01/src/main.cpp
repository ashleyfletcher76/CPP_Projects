/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:20:18 by asfletch          #+#    #+#             */
/*   Updated: 2024/03/27 11:21:03 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main( void )
{
	int	N = 5;
	Zombie	*theManyZombinators = zombieHorde(N, "John");
	for (int i = 0; i < N; i++)
		theManyZombinators[i].announce();
	delete[] theManyZombinators;
	return (0);
}
