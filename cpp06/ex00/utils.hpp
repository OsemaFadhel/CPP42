/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:40:11 by ofadhel           #+#    #+#             */
/*   Updated: 2024/07/31 15:41:59 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

#include <iostream>
#include <string>
# include <iomanip>
# include <limits>
# include <cmath>
# include <cstdlib>

int findtype(std::string _input);
void printChar(char c);
void printInt(int i);
void printFloat(float f);
void printDouble(double d);
bool isSpecialFloat(float f);
bool isSpecialDouble(double d);

#endif
