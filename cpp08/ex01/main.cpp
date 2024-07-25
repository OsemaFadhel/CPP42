/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:25:38 by ofadhel           #+#    #+#             */
/*   Updated: 2024/07/25 12:45:10 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	try
	{
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

		std::cout << "extra test addnumber" << std::endl;

		int array[] = {6, 3, 17, 9, 11};
		std::vector<int> vect(array, array + 5);

		Span sp2 = Span(5);

		sp2.addNumber(vect.begin(), vect.end());

		std::cout << sp2.shortestSpan() << std::endl;
		std::cout << sp2.longestSpan() << std::endl;

		sp.addNumber(vect.begin(), vect.end());

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
