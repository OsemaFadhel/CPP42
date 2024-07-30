/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 18:20:59 by ofadhel           #+#    #+#             */
/*   Updated: 2024/07/30 13:15:40 by ofadhel          ###   ########.fr       */
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
		Intern	someRandomIntern;
		Bureaucrat	first("Bureaucrat1",5);
		Bureaucrat	second("Bureaucrat2", 10);
		Bureaucrat	third("Bureaucrat3", 150);

		AForm	*rrf(someRandomIntern.makeForm("shrubbery creation", "tree"));
		std::cout<< "first test" <<std::endl;
		first.signForm(*rrf);
		first.executeForm(*rrf);
		delete rrf;
		AForm	*rrf2(someRandomIntern.makeForm("robotomy request", "robot"));
		std::cout<< "second test" <<std::endl;
		second.signForm(*rrf2);
		second.executeForm(*rrf2);
		delete rrf2;
		AForm	*rrf3(someRandomIntern.makeForm("shrubbery creation", "tree"));
		std::cout<< "exception test" <<std::endl;
		third.signForm(*rrf3);
		delete rrf3;
	}
	catch (const std::exception& e)
	{
		std::cout<<e.what()<<std::endl;
	}
	return (0);
}
