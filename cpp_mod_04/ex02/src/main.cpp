/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:51:12 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/08 14:07:32 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void HalfDogCatCase()
{
	AAnimal* animals[10];

	for (unsigned int i = 0; i < 6; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}
	std::cout << std::endl;
	for (unsigned int i = 0; i < 6; i++)
		animals[i]->makeSound();
	std::cout << std::endl;
	for (unsigned int i = 0; i < 6; i++)
		delete animals[i];
}

void DogBasicCase()
{
	Dog basic;

	basic.SetIdeas("Bark loudly");
	{
		Dog temp = basic;
		temp.SetIdeas("Barks like a cat");
		std::cout << "Basic Dog's idea: ";
		basic.PrintIdeas(1);
		std::cout << "Temp Dog's idea: ";
		temp.PrintIdeas(1);
	}
	std::cout << "Temp is out of scope: ";
	basic.PrintIdeas(1);
}

// void PureVirtualCase()
// {
// 	AAnimal* FirstAnimal = new AAnimal();
// 	AAnimal* SecondAnimal = new AAnimal();

// 	FirstAnimal->SetIdeas("I like nuggets");
// 	SecondAnimal->SetIdeas("I like pizza");
// 	FirstAnimal->PrintIdeas(1);
// 	SecondAnimal->PrintIdeas(1);

// 	std::cout << "FirstAnimal's memory address: " << FirstAnimal->GetBrain() << std::endl;
// 	std::cout << "SecondAnimal's memory address: " << SecondAnimal->GetBrain() << std::endl;
// 	*SecondAnimal = *FirstAnimal;
// 	std::cout << "FirstAnimal's memory address: " << FirstAnimal->GetBrain() << std::endl;
// 	std::cout << "SecondAnimal's memory address: " << SecondAnimal->GetBrain() << std::endl;
// 	FirstAnimal->PrintIdeas(1);
// 	SecondAnimal->PrintIdeas(1);

// 	delete FirstAnimal;
// 	delete SecondAnimal;
// }

void DogCaseMem()
{
	Dog* FirstAnimal = new Dog();
	Dog* SecondAnimal = new Dog();

	FirstAnimal->SetIdeas("I like nuggets");
	SecondAnimal->SetIdeas("I like pizza");
	FirstAnimal->GetBrain()->PrintIdeas(1);
	SecondAnimal->GetBrain()->PrintIdeas(1);

	std::cout << "FirstAnimal's memory address: " << FirstAnimal->GetBrain() << std::endl;
	std::cout << "SecondAnimal's memory address: " << SecondAnimal->GetBrain() << std::endl;
	*SecondAnimal = *FirstAnimal;
	std::cout << "FirstAnimal's memory address: " << FirstAnimal->GetBrain() << std::endl;
	std::cout << "SecondAnimal's memory address: " << SecondAnimal->GetBrain() << std::endl;
	std::cout << FirstAnimal->GetBrain()->GetIdeas() << std::endl;
	std::cout << SecondAnimal->GetBrain()->GetIdeas() << std::endl;
	FirstAnimal->PrintIdeas(1);
	SecondAnimal->PrintIdeas(1);

	delete FirstAnimal;
	delete SecondAnimal;
}

void CatDogCopyConstructor()
{
	Cat OriginalCat;
	std::cout << "Original Cat's memory address: "
		<< OriginalCat.GetBrain() << std::endl;
	Cat CopiedCat = OriginalCat;
	std::cout << "Copied Cat's memory address: "
		<< CopiedCat.GetBrain() << std::endl;
	Dog OriginalDog;
	std::cout << "Original Cat's memory address: "
		<< OriginalDog.GetBrain() << std::endl;
	Dog CopiedDog = OriginalDog;
	std::cout << "Copied Cat's memory address: "
		<< CopiedDog.GetBrain() << std::endl;
}

void CatCaseNoMem()
{
	Cat OriginalCat;

	OriginalCat.SetIdeas("Original Idea");
	std::cout << "Original begin idea: ";
	OriginalCat.PrintIdeas(1);
	Cat CopiedCat;
	CopiedCat = OriginalCat;
	OriginalCat.SetIdeas("New Idea");
	std::cout << "Original after change: ";
	OriginalCat.PrintIdeas(1);
	std::cout << "Copied with assignment: ";
	CopiedCat.PrintIdeas(1);
}

int	main()
{
	CatCaseNoMem();
	CatDogCopyConstructor();
	DogCaseMem();
	//PureVirtualCase();
	DogBasicCase();
	HalfDogCatCase();
}
