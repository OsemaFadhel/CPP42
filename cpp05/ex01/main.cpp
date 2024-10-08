/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 18:20:59 by ofadhel           #+#    #+#             */
/*   Updated: 2024/07/30 15:07:28 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	try {
		Bureaucrat b1("Alice", 2);
		Bureaucrat b2("Bob", 145);

		Form f1("Form1", 1, 50);
		Form f2("Form2", 150, 150);

		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
		std::cout << f1 << std::endl;
		std::cout << f2 << std::endl;
		std::cout << std::endl;

		b2.signForm(f2);
		b1.signForm(f1);
		b2.signForm(f2);

		std::cout << f1 << std::endl;
		std::cout << f2 << std::endl;

	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
