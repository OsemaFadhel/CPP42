/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 18:20:59 by ofadhel           #+#    #+#             */
/*   Updated: 2024/06/20 12:42:04 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main()
{
	try
	{
		Bureaucrat	first("Andromeda",3);
		Bureaucrat	second("Sirio", 10);
		Bureaucrat	third("Phoenix", 15);
		Intern	doItForMe;

		AForm	*randomStuff(doItForMe.makeForm("shrbbery creation", "tree"));
		std::cout<<"cairo"<<std::endl;
		first.signForm(*randomStuff);
		std::cout<<"cairo"<<std::endl;
		second.executeForm(*randomStuff);
		delete randomStuff;
	}
	catch (const std::exception& e)
	{
		std::cout<<e.what()<<std::endl;
	}
	return (0);
}
