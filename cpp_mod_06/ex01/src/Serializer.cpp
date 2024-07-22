/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:26:21 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/23 17:04:15 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::~Serializer() {}

Serializer::Serializer(const Serializer&) {}

Serializer& Serializer::operator=(const Serializer&) {return (*this);}

uintptr_t	Serializer::serialize(Data* ptr) {return (reinterpret_cast<uintptr_t>(ptr));}
Data* Serializer::deserialize(uintptr_t raw) {return (reinterpret_cast<Data*>(raw));}
