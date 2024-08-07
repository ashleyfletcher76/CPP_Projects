/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 17:39:26 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/24 14:05:04 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

int	main()
{
	srand(time(0));
	for(int i = 0; i < 5; i++)
	{
		Base* p = generate();
		std::cout << "Test - " << i + 1 << std::endl;
		identify(p);
		identify(*p);
		std::cout << "------------" << std::endl;
		delete (p);
	}
	Base* p = new Test;
	std::cout << "Test invalid class" << std::endl;
	identify(p);
	identify(*p);
	delete p;
	return (0);
}
