/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:41:22 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/03 15:35:51 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>
#include "Colours.hpp"

class Animal
{
	protected:
		std::string type;

	public:
		Animal();
		virtual ~Animal();
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		
		std::string getType( void ) const;
		virtual void makeSound( void ) const;
};

#endif
