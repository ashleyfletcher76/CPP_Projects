/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 14:57:07 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/08 13:32:43 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "Utils.hpp"
#include "ICharacter.hpp"

#define InventorySize 4

class Character : public ICharacter
{
	private:
		std::string _name;
		AMateria* _Inventory[InventorySize];
		AMateria** _Unequipped;
		unsigned int _UnequippedCount;
		unsigned int _CheckifFull;
		void Trash(AMateria* materia, unsigned int &count);

	public:
		Character();
		~Character();
		Character(const Character& other);
		Character& operator=(const Character& other);

		std::string const& getName() const;
		Character(const std::string& name);
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif
