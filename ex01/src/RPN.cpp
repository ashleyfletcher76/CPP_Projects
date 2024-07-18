/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:53:27 by asfletch          #+#    #+#             */
/*   Updated: 2024/07/18 15:33:29 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN& other) : _nums(other._nums) {}

RPN& RPN::operator=(const RPN& other)
{
	if(this != &other)
		_nums = other._nums;
	return (*this);
}

int	RPN::calculate(const std::string& str)
{
	std::istringstream iss(str);
	std::string token;
	while (iss >> token)
		processTokens(token);
	if (_nums.size() != 1)
		throw std::runtime_error("Error: invalid");
	return (_nums.top());
}

void	RPN::processTokens(const std::string& expression)
{
	if (isOperator(expression))
	{
		if (_nums.size() < 2)
			throw std::runtime_error("Error: not enough expressions");
		int	num2 = _nums.top(); _nums.pop();
		int	num1 = _nums.top(); _nums.pop();
		int	result = applyOperation(expression, num1, num2);
		_nums.push(result);
	}
	else
	{
		int	num = std::atoi(expression.c_str());
		_nums.push(num);
	}
}

bool	RPN::isOperator(const std::string& token)
{
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

int		RPN::applyOperation(const std::string& operation, int num1, int num2)
{
	if (operation == "+")
		return (num1 + num2);
	if (operation == "-")
		return (num1 - num2);
	if (operation == "*")
		return (num1 * num2);
	if (operation == "/")
		return (num1 / num2);
	throw std::runtime_error("Error: unknown operation");
}
