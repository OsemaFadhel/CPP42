/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:37:40 by ofadhel           #+#    #+#             */
/*   Updated: 2024/08/08 17:18:49 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <string>

/*
template <typename T>
void iter(T *array, int size, void (*f)(T&))
{
	for (int i = 0; i < size; i++)
		f(array[i]);
}
*/

template <typename T, typename Func>
void iter(T *array, int size, Func f)
{
	for (int i = 0; i < size; i++)
		f(array[i]);
}

#endif
