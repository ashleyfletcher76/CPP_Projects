/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:17:13 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/24 14:26:42 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
	int	random = rand() % 3;
	if (random == 0) return (new A());
	else if (random == 1) return (new B());
	else return (new C());
}

void identify(Base* p)
{
	std::cout << "Pointer: ";
	if (dynamic_cast<A*>(p))
		std::cout << "'A'" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "'B'" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "'C'" << std::endl;
	else
		std::cout << "Not a valid casting" << std::endl;
}

void identify(Base& p)
{
	std::cout << "Reference: ";
	try
	{
		A& a = dynamic_cast<A&>(p);
		std::cout <<  "'A'" << std::endl;
		(void)a;
		return ;
	}
	catch(...) {}
	try
	{
		B& b = dynamic_cast<B&>(p);
		std::cout << "'B'" << std::endl;
		(void)b;
		return ;
	}
	catch(...) {}
	try
	{
		C& c = dynamic_cast<C&>(p);
		std::cout << "'C'" << std::endl;
		(void)c;
		return ;
	}
	catch(...) {}
	std::cout << "Not a valid casting" << std::endl;
}
