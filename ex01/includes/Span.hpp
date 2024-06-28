/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:09:55 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/28 15:36:45 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <exception>

class Span
{
	private:
		unsigned int		_maxN;
		std::vector<int>	_nums;

	public:
		//Span();
		Span(unsigned int num);
		~Span();
		Span(const Span& other);
		Span& operator=(const Span& other);

		void			addNumber(int n);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();

		const std::vector<int>& getNums() const;
		unsigned int getMaxN() const;

		template<typename inputIterator>
		void	addNumbers(inputIterator begin, inputIterator end)
		{
			for(inputIterator iter = begin; iter != end; iter++)
				addNumber(*iter);
		}

		class tooManyValuesException : public std::exception{
			public:
				const char* what() const throw(){
					return ("Vector is full!");}
		};
		class notEnoughValuesException : public std::exception{
			public:
				const char* what() const throw(){
					return ("Vector doesn't have enough!");}
		};
};

#endif
