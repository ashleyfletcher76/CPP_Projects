/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:02:55 by asfletch          #+#    #+#             */
/*   Updated: 2024/07/19 11:18:14 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class PmergeMe
{
	private:
		std::vector<int> sortedVec;
		std::vector<std::pair<int, int> > pairs;

	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe&);
		PmergeMe& operator=(const PmergeMe&);
};

#endif
