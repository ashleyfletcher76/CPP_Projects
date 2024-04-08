/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 13:02:07 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/08 15:34:24 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"
#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

void ThirdTest()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* alice = new Character("Alice");
	for (int i = 0; i < 6; ++i)
	{
		AMateria* materia = src->createMateria(i % 2 == 0 ? "ice" : "cure");
		alice->equip(materia);
	}
	AMateria* extraIce = src->createMateria("ice");
	for (int i = 0; i < 6; ++i)
		alice->use(i, *alice);
	for (int i = 0; i < 5; ++i)
		alice->unequip(i);
	alice->use(0, *alice);
	delete alice;
	delete src;
	delete extraIce;
}

void SecondTest()
{

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* alice = new Character("Alice");
	ICharacter* bob = new Character("Bob");
	AMateria* ice = src->createMateria("ice");
	alice->equip(ice);
	AMateria* cure = src->createMateria("cure");
	alice->equip(cure);
	alice->use(0, *alice);
	alice->use(1, *alice);
	alice->use(0, *bob);
	alice->use(1, *bob);
	alice->unequip(0);
	alice->equip(src->createMateria("ice"));
	delete bob;
	delete alice;
	delete src;
}

void MainTest()
{
	IMateriaSource* src = new MateriaSource();
	ICharacter* me = new Character("me");
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
}

int main()
{
	MainTest();
	SecondTest();
	ThirdTest();
}
