/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:53:27 by asfletch          #+#    #+#             */
/*   Updated: 2024/07/20 15:07:40 by asfletch         ###   ########.fr       */
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
			_nums.push(c - '0');
			std::cout << "Pushed: " << (c - '0') << std::endl;
		}
		else if (isOperator(c))
		{
			std::cout << "Operator: " << c << std::endl;
			processCalculation(c);
		}
		else if (isspace(c))
			continue ;
		else
			throw std::runtime_error("Error");
	}
	if (_nums.size() != 1)
		throw std::runtime_error("Error: invalid, too many nums leftover");
	return (_nums.top());
}

void	RPN::processCalculation(char operation)
{
	if (_nums.size() < 2)
		throw std::runtime_error("Error: not enough nums");
	int	num2 = _nums.top();
	_nums.pop();
	int	num1 = _nums.top();
	_nums.pop(); // temporarily available from previous pop
	int	result = applyOperation(operation, num1, num2);
	_nums.push(result);
	std::stack<int> temp = _nums;
	std::cout << "Stack state after applying " << operation << ": ";
	while (!temp.empty())
	{
		std::cout << temp.top() << " ";
		temp.pop();
	}
	std::cout << std::endl;
}

bool	RPN::isOperator(char token)
{
	return (token == '+' || token == '-' || token == '*' || token == '/');
}

int		RPN::applyOperation(char operation, int num1, int num2)
{
	int	result;
	switch (operation)
	{
		case '+':
			result = num1 + num2;
			break ;
		case '-':
			result = num1 - num2;
			break ;
		case '*':
			result = num1 * num2;
			break ;
		case '/':
			if (num2 == 0)
				throw std::runtime_error("Error: division by zero");
			result = num1 / num2;
			break ;
		default:
			throw std::runtime_error("Error: unknown operation");
	}
	return (result);
}
