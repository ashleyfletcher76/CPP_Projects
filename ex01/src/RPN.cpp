/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:53:27 by asfletch          #+#    #+#             */
/*   Updated: 2024/07/18 16:43:23 by asfletch         ###   ########.fr       */
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
	std::string token = "";
	for(std::size_t i = 0; i < str.length(); i++)
	{
		char c = str[i];
		if (isdigit(c))
		{
			int	num = c - '0';
			_nums.push(num);
		}
		else if (isOperator(std::string(1, c)))
		{
			// if (!token.empty())
			// {
			// 	processCalculation(token);
			// 	token = "";
			// }
			processCalculation(std::string(1, c));
		}
		else if (isspace(c))
			continue ;
		else
			throw std::runtime_error("Error: invalid char");
	}
	if (!token.empty())
		processCalculation(token);
	if (_nums.size() != 1)
		throw std::runtime_error("Error: invalid, too many nums leftover");
	return (_nums.top());
}

void	RPN::processCalculation(const std::string& expression)
{
	if (isOperator(expression))
	{
		if (_nums.size() < 2)
			throw std::runtime_error("Error: not enough nums");
		int	num2 = _nums.top();
		_nums.pop();
		int	num1 = _nums.top();
		_nums.pop();
		int	result = applyOperation(expression, num1, num2);
		_nums.push(result);
	}
	else
	{
		int	num = std::atoi(expression.c_str());
		_nums.push(num);
		std::cout << num << std::endl;
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
