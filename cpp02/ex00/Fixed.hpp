/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:41:14 by ofadhel           #+#    #+#             */
/*   Updated: 2024/01/25 15:29:49 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>

class	Fixed
{
	private:
		int	fixed;
		static const int bits = 8;
	public:
		Fixed();
		Fixed(const Fixed &f);
		Fixed &operator=(const Fixed &f);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif
