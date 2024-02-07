/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:28:37 by ofadhel           #+#    #+#             */
/*   Updated: 2024/02/07 16:14:24 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixed(0)
{
	return ;
}

Fixed::Fixed(const int n)
{
	this->fixed = n * (1 << this->bits);
	return ;
}

Fixed::Fixed(const float n)
{
	this->fixed = roundf(n * (1 << this->bits));
	return ;
}

Fixed::Fixed(Fixed const &f )
{
	*this = f;
	return ;
}

Fixed &Fixed::operator=( const Fixed &f )
{
	this->fixed = f.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	return ;
}

int Fixed::getRawBits( void ) const
{
	return (this->fixed);
}

void Fixed::setRawBits( int const raw )
{
	this->fixed = raw;
}

float Fixed::toFloat( void ) const
{
	return ((float)this->fixed / (float)(1 << this->bits));
}

int Fixed::toInt( void ) const
{
	return (this->fixed >> this->bits);
}

bool operator<(const Fixed &f1, const Fixed &f2)
{
	return (f1.getRawBits() < f2.getRawBits());
}

inline bool Fixed::operator<(const Fixed &f)
{
	return (this->getRawBits() < f.getRawBits());
}

inline bool Fixed::operator>(const Fixed &f)
{
	return (this->getRawBits() > f.getRawBits());
}

inline bool Fixed::operator<=(const Fixed &f)
{
	return (this->getRawBits() <= f.getRawBits());
}

inline bool Fixed::operator>=(const Fixed &f)
{
	return (this->getRawBits() >= f.getRawBits());
}


inline bool Fixed::operator==(const Fixed &f)
{
	return (this->getRawBits() == f.getRawBits());
}

inline bool Fixed::operator!=(const Fixed &f)
{
	return (this->getRawBits() != f.getRawBits());
}

Fixed &Fixed::operator+(const Fixed &f)
{
	this->fixed += f.getRawBits();
	return (*this);
}

Fixed &Fixed::operator-(const Fixed &f)
{
	this->fixed -= f.getRawBits();
	return (*this);
}

Fixed &Fixed::operator*(const Fixed &f)
{
	this->fixed *= f.getRawBits() / (1 << this->bits);
	return (*this);
}

Fixed &Fixed::operator/(const Fixed &f)
{
	this->fixed /= f.getRawBits() / (1 << this->bits);
	return (*this);
}

Fixed &Fixed::operator++()
{
	this->fixed++;
	return (*this);
}


Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	operator++();
	return (tmp);
}

Fixed &Fixed::operator--()
{
	this->fixed--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	operator--();
	return (tmp);
}

Fixed &Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f1.getRawBits() < f2.getRawBits())
		return (f1);
	return (f2);
}

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2)
{
	if (f1.getRawBits() < f2.getRawBits())
		return (f1);
	return (f2);
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2)
{
	if (f1.getRawBits() < f2.getRawBits())
		return (f2);
	return (f1);
}

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2)
{
	if (f1.getRawBits() < f2.getRawBits())
		return (f2);
	return (f1);
}

std::ostream &operator<<(std::ostream &o, Fixed const &i)
{
	o << i.toFloat();
	return (o);
}
