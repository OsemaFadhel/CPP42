/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:56:10 by ofadhel           #+#    #+#             */
/*   Updated: 2024/02/07 16:13:38 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixed = n * (1 << this->bits);
	return ;
}

Fixed::Fixed(const float n)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixed = roundf(n * (1 << this->bits));
	return ;
}

Fixed::Fixed(Fixed const &f )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
	return ;
}

Fixed &Fixed::operator=( const Fixed &f )
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->fixed = f.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
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

std::ostream &operator<<(std::ostream &o, Fixed const &i)
{
	o << i.toFloat();
	return (o);
}
