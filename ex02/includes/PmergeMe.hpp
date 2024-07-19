/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:02:55 by asfletch          #+#    #+#             */
/*   Updated: 2024/07/19 15:56:31 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <exception>
#include <ctime>
#include <list>

class PmergeMe
{
	private:
		// vector
		std::vector<int> _sortedVec;
		std::vector<std::pair<int, int> > _vecPairs;
		std::vector<int> _vecNums;
		std::vector<int>::iterator findInsertionPosition(std::vector<int>& sortedVec, int value);
		void	printVector(const std::vector<int>& vec) const;
		// list
		std::list<int> _sortedList;
		std::list<std::pair<int, int> > _listPairs;
		std::list<int> _listNums;
		std::list<int>::iterator findInsertionPosition(std::list<int>& sortedList, int value);
		void	printList(const std::list<int>& list) const;


	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe&);
		PmergeMe& operator=(const PmergeMe&);

		void	executeVec(const std::string& argv);
		void	executeList(const std::string& argv);
		void	printBegin(const std::string& argv) const;
};

#endif
