/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:28:37 by ofadhel           #+#    #+#             */
/*   Updated: 2024/07/22 18:05:30 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : _n(n)
{
}

Span::Span(const Span &src) : _n(src._n), _v(src._v)
{
}

Span &Span::operator=(const Span &src)
{
	if (this != &src)
	{
		_n = src._n;
		_v = src._v;
	}
	return *this;
}

Span::~Span()
{
}

void Span::addNumber(int n)
{
	if (_v.size() >= _n)
		throw FullException();
	_v.push_back(n);
}

unsigned int Span::shortestSpan()
{
	if (_v.size() <= 1)
		throw NoSpanException();
	std::vector<int> tmp = _v;
	std::sort(tmp.begin(), tmp.end());
	unsigned int min = tmp[1] - tmp[0];
	for (unsigned int i = 2; i < tmp.size(); ++i)
	{
		if (static_cast<unsigned int>(tmp[i] - tmp[i - 1]) < min)
			min = tmp[i] - tmp[i - 1];
	}
	return min;
}

unsigned int Span::longestSpan()
{
	if (_v.size() <= 1)
		throw NoSpanException();
	std::vector<int> tmp = _v;
	std::sort(tmp.begin(), tmp.end());
	return tmp[tmp.size() - 1] - tmp[0];
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (_v.size() + std::distance(begin, end) > _n)
		throw FullException();
	_v.insert(_v.end(), begin, end);
}

const char *Span::FullException::what() const throw()
{
	return ("Container is full");
}

const char *Span::NoSpanException::what() const throw()
{
	return ("No span to find");
}
