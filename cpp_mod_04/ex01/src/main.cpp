/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:51:12 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/05 11:18:41 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void DogCaseMem()
{
	Dog* FirstAnimal = new Dog();
	Dog* SecondAnimal = new Dog();

	FirstAnimal->SetIdea("I like nuggets");
	SecondAnimal->SetIdea("I like pizza");
	FirstAnimal->GetBrain()->PrintIdeas(1);
	SecondAnimal->GetBrain()->PrintIdeas(1);

	std::cout << "FirstAnimal's memory address: "
		<< FirstAnimal->GetBrain() << std::endl;
	std::cout << "SecondAnimal's memory address: "
		<< SecondAnimal->GetBrain() << std::endl;

	*SecondAnimal = *FirstAnimal;

	std::cout << "FirstAnimal's memory address: "
		<< FirstAnimal->GetBrain() << std::endl;
	std::cout << "SecondAnimal's memory address: "
		<< SecondAnimal->GetBrain() << std::endl;
	// std::cout << FirstAnimal->GetBrain()->GetIdeas() << std::endl;
	// std::cout << SecondAnimal->GetBrain()->GetIdeas() << std::endl;
	FirstAnimal->PrintIdeas(1);
	SecondAnimal->PrintIdeas(1);

	delete FirstAnimal;
	delete SecondAnimal;
}

void CatCaseMem()
{
	Cat* FirstAnimal = new Cat();
	Cat* SecondAnimal = new Cat();

	FirstAnimal->SetIdea("I like nuggets");
	SecondAnimal->SetIdea("I like pizza");
	FirstAnimal->GetBrain()->PrintIdeas(1);
	SecondAnimal->GetBrain()->PrintIdeas(1);

	std::cout << "FirstAnimal's memory address: "
		<< FirstAnimal->GetBrain() << std::endl;
	std::cout << "SecondAnimal's memory address: "
		<< SecondAnimal->GetBrain() << std::endl;

	*SecondAnimal = *FirstAnimal;

	std::cout << "FirstAnimal's memory address: "
		<< FirstAnimal->GetBrain() << std::endl;
	std::cout << "SecondAnimal's memory address: "
		<< SecondAnimal->GetBrain() << std::endl;
	std::cout << FirstAnimal->GetBrain()->GetIdeas() << std::endl;
	std::cout << SecondAnimal->GetBrain()->GetIdeas() << std::endl;
	SecondAnimal->PrintIdeas(1);

	delete FirstAnimal;
	delete SecondAnimal;
}

void FifthCase()
{
	Cat OriginalCat;
	std::cout << "Original Cat's memory address: "
		<< OriginalCat.GetBrain() << std::endl;
	Cat CopiedCat = OriginalCat;
	std::cout << "Copied Cat's memory address: "
		<< CopiedCat.GetBrain() << std::endl;
}

void DogCaseNoMem()
{
	Dog OriginalDog;

	OriginalDog.SetIdea("Original Idea");
	std::cout << "Original begin idea: ";
	OriginalDog.PrintIdeas(1);
	Dog CopiedDog;
	CopiedDog = OriginalDog;
	OriginalDog.SetIdea("New Idea");
	std::cout << "Original after change: ";
	OriginalDog.PrintIdeas(1);
	std::cout << "Copied with assignment: ";
	CopiedDog.PrintIdeas(1);
}

void CatCaseNoMem()
{
	Cat OriginalCat;

	OriginalCat.SetIdea("Original Idea");
	std::cout << "Original begin idea: ";
	OriginalCat.PrintIdeas(1);
	Cat CopiedCat;
	CopiedCat = OriginalCat;
	OriginalCat.SetIdea("New Idea");
	std::cout << "Original after change: ";
	OriginalCat.PrintIdeas(1);
	std::cout << "Copied with assignment: ";
	CopiedCat.PrintIdeas(1);
}

void ThirdCase()
{
	WrongAnimal* FirstAnimal = new WrongCat();
	WrongCat* SecondAnimal = new WrongCat();

	FirstAnimal->makeSound();
	SecondAnimal->makeSound();
	delete FirstAnimal;
	delete SecondAnimal;
}

void SecondCase()
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

int	main()
{
	// Firstcase();
	//SecondCase();
	// ThirdCase();
	//CatCaseNoMem();
	//DogCaseNoMem();
	// FifthCase();
	DogCaseMem();
	//CatCaseMem();
}
