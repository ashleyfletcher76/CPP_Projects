/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 12:19:41 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/29 14:19:39 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() {}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T>& other) : std::stack<T>(other) {}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& other)
{
	if (this != &other)
		std::stack<T>::operator=(other);
	return(*this);
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {return (this->c.begin());}
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {return (this->c.end());}
template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin() {return (this->c.rbegin());}
template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend() {return (this->c.rend());}

#endif
