/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:48:15 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/04 07:05:20 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include <iostream>
#include <string>
#include "WrongAnimal.hpp"
#include "Colours.hpp"

class WrongCat : public WrongAnimal
{
	private:

	public:
		WrongCat();
		~WrongCat();
		WrongCat(const WrongCat& other);
		WrongCat& operator=(const WrongCat& other);
		void makeSound( void ) const;
};

#endif
