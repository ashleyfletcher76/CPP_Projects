/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 14:57:07 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/06 15:01:36 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "Utils.hpp"
#include "ICharacter.hpp"

class Character : ICharacter
{
	private:

	public:
		Character();
		~Character();
		Character(const Character& other);
		Character& operator=(const Character& other);

		std::string const& getName() const;
};

#endif
