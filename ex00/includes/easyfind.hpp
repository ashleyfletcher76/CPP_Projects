/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:17:25 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/27 17:05:58 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <exception>

class NotFoundException : public std::exception
{
	public:
		const char* what() const throw() {
			return ("Not found exception!");
		}
};

template<typename T>
typename T::iterator easyfind(T& container, int num)
{
	typename T::iterator it = std::find(container.begin(), container.end(), num);
	if (it == container.end())
		throw NotFoundException();
	return (it);
}


#endif
