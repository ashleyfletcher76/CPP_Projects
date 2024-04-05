/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:44:51 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/05 11:07:20 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"
#include "Colours.hpp"

class Cat : public Animal
{
	private:
		Brain* brains;
	public:
		Cat();
		virtual ~Cat();
		Cat(const Cat& other);
		Cat& operator=(const Cat& other);

		void makeSound( void ) const;
		Brain* GetBrain( void );
		void SetIdea(const std::string& idea) const;
		void PrintIdeas(unsigned int NumIdeas);
};

#endif
