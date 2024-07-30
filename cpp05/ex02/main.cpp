/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 18:20:59 by ofadhel           #+#    #+#             */
/*   Updated: 2024/07/30 12:35:40 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main()
{
	Bureaucrat	bureaucrat("Bureaucrat", 1);
	PresidentialPardonForm	presidentialPardonForm("presidentialPardon");
	RobotomyRequestForm		robotomyRequestForm("robotomyRequest");
	ShrubberyCreationForm	shrubberyCreationForm("shrubberyCreation");

	bureaucrat.signForm(presidentialPardonForm);
	bureaucrat.signForm(robotomyRequestForm);
	bureaucrat.signForm(shrubberyCreationForm);
	bureaucrat.executeForm(presidentialPardonForm);
	bureaucrat.executeForm(robotomyRequestForm);
	bureaucrat.executeForm(shrubberyCreationForm);

	return (0);
}
