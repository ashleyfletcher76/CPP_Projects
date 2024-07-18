/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:53:51 by asfletch          #+#    #+#             */
/*   Updated: 2024/07/18 16:35:58 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <stdexcept>
#include <sstream>
#include <cstdlib>

class RPN
{
	private:
		std::stack<int> _nums;
		void	processCalculation(const std::string& expression);
		bool	isOperator(const std::string& token);
		int		applyOperation(const std::string& operation, int num1, int num2);

	public:
		RPN();
		~RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);

		int	calculate(const std::string& str);
};

#endif
