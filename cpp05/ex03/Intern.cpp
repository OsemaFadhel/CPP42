/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:10:28 by ofadhel           #+#    #+#             */
/*   Updated: 2024/06/19 11:50:28 by ofadhel          ###   ########.fr       */
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
	std::string names[3] = { "shrubbery creation",
								"robotomy request",
								"presidential pardon" };

	for (int i = 0; i < 3; i++)
	{
		if (names[i] == formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (formCreators[i](target));
		}
	}
	std::cout << "Intern can't create " << formName << " because it doesn't exist" << std::endl;
	return (NULL);
}

AForm *Intern::createShrubberyCreationForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::createRobotomyRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::createPresidentialPardonForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}
