/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:27:29 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/23 17:31:05 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

void	showAfterConversion(Data *EmptyData)
{
	std::cout << "-------------" << std::endl;
	std::cout << "New EmptyData address" << std::endl;
	std::cout << EmptyData << std::endl;
	std::cout << EmptyData->str << std::endl;
	std::cout << EmptyData->num << std::endl;
	std::cout << "-------------" << std::endl;
}

void	showMemAddresses(Data* DataExample, Data* DataExample2, Data* EmptyData)
{
	std::cout << "Original DataExample address" << std::endl;
	std::cout << DataExample << std::endl;
	std::cout << "-------------" << std::endl;
	std::cout << "Orignal DataExample2 address" << std::endl;
	std::cout << DataExample2 << std::endl;
	std::cout << "-------------" << std::endl;
	std::cout << "Orignal EmptyData address" << std::endl;
	std::cout << EmptyData << std::endl;
}

int	main()
{
	Data* DataExample = new Data;
	Data* DataExample2 = new Data;
	Data* EmptyData = NULL;
	uintptr_t RawExample;
	uintptr_t RawExample2;

	DataExample->str = "Cookies";
	DataExample->num = 69;
	DataExample2->str = "Chicken nuggets";
	DataExample2->num = 100;

	showMemAddresses(DataExample, DataExample2, EmptyData);
	RawExample = Serializer::serialize(DataExample);
	EmptyData = Serializer::deserialize(RawExample);
	showAfterConversion(EmptyData);
	std::cout << "Now Convert EmptyData again" << std::endl;
	RawExample2 = Serializer::serialize(DataExample2);
	EmptyData = Serializer::deserialize(RawExample2);
	showAfterConversion(EmptyData);
	delete DataExample;
	delete DataExample2;
	return (0);
}
