/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:46:04 by ofadhel           #+#    #+#             */
/*   Updated: 2024/07/29 15:40:48 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::~RPN()
{
}

RPN::RPN(RPN const &obj)
{
	*this = obj;
}

RPN &RPN::operator=(RPN const &obj)
{
	_stack = obj._stack;
	return *this;
}

void RPN::check(std::string const &av)
{
	for (size_t i = 0; i < av.length(); i++)
	{
		if (isdigit(av[i]))
		{
			if (av[1] - '0' < 0 || av[1] - '0' > 9)
				throw std::invalid_argument("Error");
			continue;
		}
		if (av[i] == ' ' || av[i] == '+' || av[i] == '-' || av[i] == '*' || av[i] == '/')
			continue;
		throw std::invalid_argument("Error");
	}
}

void RPN::execute(std::string const &av)
{
	check(av);
	if (av.length() == 0)
		throw std::runtime_error("Error");
	for (size_t i = 0; i < av.length(); i++)
	{
		if (av[i] == ' ')
			continue;
		if (isdigit(av[i]))
			_stack.push(av[i] - '0');
		else
			calculate(av[i]);
	}
	/*if (_stack.size() != 1)
		throw std::runtime_error("Error");*/
	std::cout << _stack.top() << std::endl;
}

void RPN::calculate(char c)
{
	if (_stack.size() < 2)
		throw std::runtime_error("Error: not enough numbers");
	int a = _stack.top();
	_stack.pop();
	int b = _stack.top();
	_stack.pop();
	switch (c)
	{
		case '+':
			_stack.push(b + a);
			break;
		case '-':
			_stack.push(b - a);
			break;
		case '*':
			_stack.push(b * a);
			break;
		case '/':
			_stack.push(b / a);
			break;
	}
}
