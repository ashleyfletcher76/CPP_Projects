/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 13:02:07 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/07 16:16:29 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"
#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	if (tmp)
		me->equip(tmp);
	else
		std::cerr << "Failed to create ice materia." << std::endl;
	tmp = src->createMateria("cure");
	if (tmp)
		me->equip(tmp);
	else
		std::cerr << "Failed to create cure materia." << std::endl;
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->unequip(1);
	delete bob;
	delete me;
	delete src;
	return 0;
}

// int main()
// {
// 	 MateriaSource source;

// 	AMateria* ice = new Ice();
// 	source.learnMateria(ice);
// 	AMateria* clonedIce = source.createMateria("ice");

// 	if (clonedIce)
// 		std::cout << "Cloned Ice Materia created." << std::endl;
// 	else
// 		std::cout << "No such Materia found." << std::endl;
// 	delete clonedIce;
// 	delete ice;

// 	return 0;
// }
