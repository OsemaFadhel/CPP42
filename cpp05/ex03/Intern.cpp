/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:10:28 by ofadhel           #+#    #+#             */
/*   Updated: 2024/06/20 12:45:41 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(Intern const &src)
{
	(void)src;
}

Intern &Intern::operator=(Intern const &src)
{
	(void)src;
	return (*this);
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
	std::string formTypes[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	AForm *(Intern::*FormCreator[3])(const std::string &target) = {
		&Intern::createShrubberyCreationForm,
		&Intern::createRobotomyRequestForm,
		&Intern::createPresidentialPardonForm
	};

	for (int i = 0; i < 3; i++)
	{
		if (formName == formTypes[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*FormCreator[i])(target);
		}
	}

	if (formName != formTypes[0] && formName != formTypes[1] && formName != formTypes[2])
		throw std::invalid_argument("Invalid form name");
	return (NULL);
}

AForm *Intern::createShrubberyCreationForm(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomyRequestForm(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidentialPardonForm(const std::string &target)
{
	return new PresidentialPardonForm(target);
}
