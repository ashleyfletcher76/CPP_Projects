/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:51:07 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/28 16:28:14 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <exception>

template <typename T>
class MutantStack : public std::stack<T>
{
	private:


	public:
		MutantStack();
		~MutantStack();
		MutantStack(const MutantStack&);
		MutantStack& operator=(const MutantStack&);
};

template <typename T>
MutantStack<T>::MutantStack() {}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T>&) {}

template <typename T>
MutantStack<T>& MutantStack::operator=(const MutantStack<T>&) {return(*this);}

#endif
