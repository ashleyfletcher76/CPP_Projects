/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:50:08 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/29 15:21:18 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include "MutantStack.tpp"

void	checkOperators()
{
	MutantStack<int> mStack;

	for(std::size_t i = 0; i < 10; i++)
		mStack.push((i + 1) * 10);
	std::cout << "=== PRINT STACK ===" << std::endl;
	for(MutantStack<int>::iterator iter = mStack.begin(); iter != mStack.end(); iter++)
		std::cout << *iter << std::endl;
	MutantStack<int> copyMStack(mStack);
	MutantStack<int> copyMAssign;
	std::cout << "=== PRINT SECOND STACK ===" << std::endl;
	for(MutantStack<int>::iterator iter = copyMStack.begin(); iter != copyMStack.end(); iter++)
		std::cout << *iter << std::endl;
	copyMAssign = mStack;
	for(std::size_t i = 10; i < 20; i++)
		mStack.push((i + 1) * 10);
	std::cout << "=== PRINT ORIGINAL STACK AFTER CHANGE ===" << std::endl;
	for(MutantStack<int>::iterator iter = mStack.begin(); iter != mStack.end(); iter++)
		std::cout << *iter << std::endl;
	std::cout << "=== PRINT THIRD STACK ===" << std::endl;
	for(MutantStack<int>::iterator iter = copyMAssign.begin(); iter != copyMAssign.end(); iter++)
		std::cout << *iter << std::endl;
}

void	iteratorCheck()
{
	MutantStack<int> mStack;

	for(std::size_t i = 0; i < 10; i++)
		mStack.push((i + 1) * 10);
	std::cout << "=== CHECK EMPTY ===" << std::endl;
	std::cout << "Is stack empty: " << (mStack.empty() ? "Yes" : "No") << std::endl;
	std::cout << "=== PRINT STACK ===" << std::endl;
	for(MutantStack<int>::iterator iter = mStack.begin(); iter != mStack.end(); iter++)
		std::cout << *iter << std::endl;
	mStack.pop();
	std::cout << "=== AFTER POP ===" << std::endl;
	for(MutantStack<int>::iterator iter = mStack.begin(); iter != mStack.end(); iter++)
		std::cout << *iter << std::endl;
	std::cout << "=== CHECK SIZE ===" << std::endl;
	std::cout << "Stack size = " << mStack.size() << std::endl;
	std::cout << "=== CHECK TOP ===" << std::endl;
	std::cout << "Top element = " << mStack.top() << std::endl;
}

void	reverseIteratorCheck()
{
	MutantStack<int> mStack;

	for(std::size_t i = 0; i < 10; i++)
		mStack.push((i + 1) * 10);
	std::cout << "=== CHECK EMPTY ===" << std::endl;
	std::cout << "Is stack empty: " << (mStack.empty() ? "Yes" : "No") << std::endl;
	std::cout << "=== PRINT STACK ===" << std::endl;
	for(MutantStack<int>::reverse_iterator iter = mStack.rbegin(); iter != mStack.rend(); iter++)
		std::cout << *iter << std::endl;
	mStack.pop();
	std::cout << "=== AFTER POP ===" << std::endl;
	for(MutantStack<int>::reverse_iterator iter = mStack.rbegin(); iter != mStack.rend(); iter++)
		std::cout << *iter << std::endl;
	std::cout << "=== CHECK SIZE ===" << std::endl;
	std::cout << "Stack size = " << mStack.size() << std::endl;
	std::cout << "=== CHECK TOP ===" << std::endl;
	std::cout << "Top element = " << mStack.top() << std::endl;
}

void	subjectMain()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}

int	main()
{
	iteratorCheck();
	reverseIteratorCheck();
	subjectMain();
	checkOperators();
}
