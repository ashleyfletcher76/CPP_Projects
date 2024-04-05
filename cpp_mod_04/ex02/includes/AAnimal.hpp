/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:41:22 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/05 13:32:50 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>
#include <string>
#include "Brain.hpp"
#include "Colours.hpp"

class AAnimal
{
	protected:
		std::string type;
	public:
		AAnimal();
		AAnimal(std::string name);
		virtual ~AAnimal();
		AAnimal(const AAnimal& other);
		AAnimal& operator=(const AAnimal& other);

		std::string getType( void ) const;
		virtual void makeSound( void ) const = 0;
		virtual void SetIdeas(const std::string& idea) const;
		virtual void PrintIdeas(unsigned int NumIdeas);
		virtual Brain* GetBrain( void );
};

#endif
