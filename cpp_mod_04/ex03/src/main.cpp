/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 13:02:07 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/08 11:48:49 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"
#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

void	leaks(void)
{
	system("leaks ex03");
}

void SecondTest()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* alice = new Character("Alice");
	ICharacter* bob = new Character("Bob");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	tmp = src->createMateria("ice");
	alice->equip(tmp);
	tmp = src->createMateria("cure");
	tmp = src->createMateria("cure");
	alice->equip(tmp);
	alice->use(0, *alice);
	alice->use(1, *alice);
	alice->use(0, *alice);
	alice->use(1, *alice);
	alice->use(0, *bob);
	alice->use(1, *bob);
	alice->use(2, *bob);
	alice->unequip(0);
	alice->use(0, *bob);
	alice->equip(src->createMateria("ice"));
	alice->use(0, *bob);
	delete bob;
	delete alice;
	delete src;
}

void MainTest()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
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
	//MainTest();
	SecondTest();
	atexit(leaks);
}
