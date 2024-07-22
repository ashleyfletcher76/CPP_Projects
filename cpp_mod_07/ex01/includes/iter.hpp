/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:01:40 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/26 12:15:26 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template<typename A, typename F>
void	iter(A* array, std::size_t len, F function)
{
	for(std::size_t i = 0; i < len; i++)
		function(array[i]);
}

template<typename T>
void	square(T num)
{
	T result;

	result = num * num;
	std::cout << num << " * " << num << " = " << result << std::endl;
}

template<typename T>
void	printInt(T num)
{
	std::cout << num << " ";
}

template<typename T>
void	printString(T str)
{
	std::cout << "'" << str << "' ";
}

#endif
