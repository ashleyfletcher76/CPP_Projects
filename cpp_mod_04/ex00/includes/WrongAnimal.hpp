/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:47:21 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/04 06:49:31 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
#include <string>
#include "Colours.hpp"

class WrongAnimal
{
	protected:
		std::string type;

	public:
		WrongAnimal();
		virtual ~WrongAnimal();
		WrongAnimal(const WrongAnimal& other);
		WrongAnimal& operator=(const WrongAnimal& other);
		void makeSound( void ) const;
};

#endif
