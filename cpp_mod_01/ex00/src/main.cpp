/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:11:45 by asfletch          #+#    #+#             */
/*   Updated: 2024/03/27 09:57:03 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main( void )
{
	randomChump("David");
	Zombie *HeapZombie = newZombie("John");
	HeapZombie->announce();
	delete HeapZombie;
	return (0);
}
