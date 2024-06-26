/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:46:36 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/05 13:20:14 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include <string>
#include "AAnimal.hpp"
#include "Colours.hpp"

class Dog : public AAnimal
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
