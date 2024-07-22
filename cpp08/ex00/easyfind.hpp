/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 22:16:52 by ofadhel           #+#    #+#             */
/*   Updated: 2024/07/22 16:21:17 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

template <typename T>
int easyfind(T &container, int n)
{
	if (std::find(container.begin(), container.end(), n) == container.end())
		return std::cout << n << " not found" << std::endl, -1;
	std::cout << n << " found" << std::endl;
	return n;
}

#endif
