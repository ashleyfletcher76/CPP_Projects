/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:41:22 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/05 11:07:13 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>
#include "Brain.hpp"
#include "Colours.hpp"

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(std::string name);
		virtual ~Animal();
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);

		std::string getType( void ) const;
		virtual void makeSound( void ) const;
		virtual void SetIdea(const std::string& idea) const;
		void PrintIdeas(unsigned int NumIdeas);
		virtual Brain* GetBrain( void );
};

#endif
