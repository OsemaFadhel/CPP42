/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 18:20:59 by ofadhel           #+#    #+#             */
/*   Updated: 2024/07/30 16:00:59 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main()
{
	try
	{
		Bureaucrat	bureaucrat("Bureaucrat", 1);
		Bureaucrat	bureaucrat2("Bureaucrat2", 150);
		PresidentialPardonForm	presidentialPardonForm("presidentialPardon");
		RobotomyRequestForm		robotomyRequestForm("robotomyRequest");
		ShrubberyCreationForm	shrubberyCreationForm("shrubberyCreation");

		bureaucrat.signForm(presidentialPardonForm);
		bureaucrat.signForm(robotomyRequestForm);
		bureaucrat.signForm(shrubberyCreationForm);
		bureaucrat.executeForm(presidentialPardonForm);
		bureaucrat.executeForm(robotomyRequestForm);
		bureaucrat.executeForm(shrubberyCreationForm);
		bureaucrat2.signForm(presidentialPardonForm);
		std::cout << "KANYE TEST" << std::endl;

	}
	catch (const std::exception& e)
	{
		std::cout<< e.what() << std::endl;
	}

	return (0);
}
