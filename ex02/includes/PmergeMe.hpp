/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:02:55 by asfletch          #+#    #+#             */
/*   Updated: 2024/07/19 12:50:53 by asfletch         ###   ########.fr       */
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

class PmergeMe
{
	private:
		std::vector<int> _sortedVec;
		std::vector<std::pair<int, int> > _pairs;
		std::vector<int> _nums;
		std::vector<int>::iterator findInsertionPosition(std::vector<int>& sortedVec, int value);
		void	printVector(const std::vector<int>& vec) const;

	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe&);
		PmergeMe& operator=(const PmergeMe&);

		void	executeVec(const std::string& argv);
};

#endif
