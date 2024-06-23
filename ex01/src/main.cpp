/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:27:29 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/23 17:08:39 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main()
{
	Data* DataExample = new Data;
	Data* Data2Example;
	uintptr_t RawExample;

	DataExample->str = "Cookies";
	DataExample->num = 69;

	std::cout << "Original DataExample address" << std::endl;
	std::cout << DataExample << std::endl;
	std::cout << "-------------" << std::endl;
	std::cout << "Orignal Data2Example address" << std::endl;
	std::cout << Data2Example << std::endl;
	RawExample = Serializer::serialize(DataExample);
	Data2Example = Serializer::deserialize(RawExample);
	std::cout << "-------------" << std::endl;
	std::cout << "New Data2Example address" << std::endl;
	std::cout << Data2Example << std::endl;
	std::cout << Data2Example->str << std::endl;
	std::cout << Data2Example->num << std::endl;
	delete DataExample;
	return (0);
}
