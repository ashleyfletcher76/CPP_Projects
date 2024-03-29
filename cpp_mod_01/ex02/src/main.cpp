/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:47:39 by asfletch          #+#    #+#             */
/*   Updated: 2024/03/27 12:56:33 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main( void )
{
	std::string str = "HI THIS IS BRAIN";
	std::string &ref = str;
	std::string *ptr = &str;

	//string
	std::cout << str << std::endl;
	std::cout << ref << std::endl;
	std::cout << *ptr << std::endl;

	std::cout << "--------" << std::endl;

	//memory addressess
	std::cout << &str << std::endl;
	std::cout << &ref << std::endl;
	std::cout << ptr << std::endl;
}
