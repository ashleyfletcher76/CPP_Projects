/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:51:12 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/04 15:09:54 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void SixthCase( void )
{
	Animal* FirstAnimal = new Cat();
	Animal* SecondAnimal = new Cat();

	FirstAnimal->SetIdea("I like nuggets");
	SecondAnimal->SetIdea("I like pizza");
	std::cout << "FirstAnimal's memory address: "
		<< FirstAnimal->GetBrainAddress() << std::endl;
	std::cout << "FirstAnimal's memory address: "
		<< SecondAnimal->GetBrainAddress() << std::endl;

	delete FirstAnimal;
	delete SecondAnimal;
}

void FifthCase( void )
{
	Cat OriginalCat;
	std::cout << "Original Cat's memory address: "
		<< OriginalCat.GetBrainAddress() << std::endl;
	Cat CopiedCat = OriginalCat;
	std::cout << "Copied Cat's memory address: "
		<< CopiedCat.GetBrainAddress() << std::endl;
}

void FourthCase( void )
{
	Cat OriginalCat;

	OriginalCat.SetIdea("Original Idea");
	std::cout << "Original begin idea: ";
	OriginalCat.PrintIdeas(1);
	Cat CopiedCat = OriginalCat;
	OriginalCat.SetIdea("New Idea");
	std::cout << "Original after change: ";
	OriginalCat.PrintIdeas(1);
	std::cout << "Copied with assignment: ";
	CopiedCat.PrintIdeas(1);
}

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

void Firstcase()
{
	Cat* FirstAnimal = new Cat();
	Cat* SecondAnimal = new Cat();

	FirstAnimal->SetIdea("Chickens nuggets");
	SecondAnimal->SetIdea("Goats");
	FirstAnimal->PrintIdeas(2);
	SecondAnimal->PrintIdeas(2);
	*SecondAnimal = *FirstAnimal;
	SecondAnimal->PrintIdeas(2);
	delete FirstAnimal;
	delete SecondAnimal;
}

int	main( void )
{
	Firstcase();
	SecondCase();
	ThirdCase();
	FourthCase();
	FifthCase();
	SixthCase();
}
