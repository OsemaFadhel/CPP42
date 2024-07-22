/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 22:16:54 by ofadhel           #+#    #+#             */
/*   Updated: 2024/07/22 16:13:13 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main()
{
	int array[] = {1, 2, 3, 4, 5};

	std::vector<int> vect(array, array + 5);
	std::list<int> lst(array, array + 5);

	std::cout << "Vector: ";
	easyfind(vect, 3);
	std::cout << "List: ";
	easyfind(lst, 3);
	std::cout << "Vector: ";
	easyfind(vect, 42);
	std::cout << "List: ";
	easyfind(lst, 42);

	return 0;
}
