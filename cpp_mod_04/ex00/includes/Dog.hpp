/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:46:36 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/04 07:05:16 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Colours.hpp"

class Dog : public Animal
{
	private:

	public:
		Dog();
		~Dog();
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);
		void makeSound( void ) const;
};

#endif
