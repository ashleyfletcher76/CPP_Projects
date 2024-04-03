/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:51:12 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/03 17:15:38 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void ThirdCase( void )
{
	WrongAnimal* FirstAnimal = new WrongCat();
	WrongCat* SecondAnimal = new WrongCat();

	FirstAnimal->makeSound();
	SecondAnimal->makeSound();
	delete FirstAnimal;
	delete SecondAnimal;
}

void SecondCase( void )
{
	Animal* FirstAnimal = new Animal();
	Animal* SecondAnimal = new Cat();
	Animal* ThirdAnimal = FirstAnimal;

	std::cout << "First animal = " << FirstAnimal->getType() << " " << std::endl;
	std::cout << "Second animal = " << SecondAnimal->getType() << " " << std::endl;
	std::cout << "Third animal = " << ThirdAnimal->getType() << " " << std::endl;

	*FirstAnimal = *SecondAnimal;

	std::cout << "First animal = " << FirstAnimal->getType() << " " << std::endl;
	std::cout << "Second animal = " << SecondAnimal->getType() << " " << std::endl;

	delete FirstAnimal;
	delete SecondAnimal;
}

int Firstcase()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	delete j;
	delete i;
	delete meta;
	return 0;
}

int	main( void )
{
	Firstcase();
	SecondCase();
	ThirdCase();
}
