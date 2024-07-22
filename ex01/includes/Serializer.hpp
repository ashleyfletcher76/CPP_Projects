/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:17:44 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/23 16:44:33 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <cmath>
#include <stdint.h>

typedef struct Data
{
	std::string	str;
	int			num;
}	Data;

class Serializer
{
	private:
		Serializer();
		~Serializer();
		Serializer(const Serializer&);
		Serializer& operator=(const Serializer&);

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
