/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:46:36 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/09 07:36:18 by asfletch         ###   ########.fr       */
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
		Brain* brain;
		
	public:
		Dog();
		virtual ~Dog();
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);

		void makeSound( void ) const;
		Brain* GetBrain( void );
		void SetIdeas(const std::string& idea) const;
		void PrintIdeas(unsigned int NumIdeas);
};

#endif
