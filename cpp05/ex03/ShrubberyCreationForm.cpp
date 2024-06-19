/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:31:39 by ofadhel           #+#    #+#             */
/*   Updated: 2024/06/10 15:27:42 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137)
{
	_target = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : AForm(src)
{
	_target = src._target;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src)
{
	if (this == &src)
		_target = src._target;
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();
	if (this->getSigned() == false)
		throw FormNotSignedException();

	std::ofstream file(_target + "_shrubbery");
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file" << std::endl;
		return ;
	}

	file << "          &&& &&  & &&" << std::endl;
    file << "      && &\\/&\\|& ()|/ @, &&" << std::endl;
    file << "      &\\/(/&/&||/& /_/)_&/_&" << std::endl;
    file << "   &() &\\/&|()|/&\\/ '%\" & ()" << std::endl;
    file << "  &_\\_&&_\\ |& |&&/&__%_/_& &&" << std::endl;
    file << "&&   && & &| &| /& & % ()& /&&" << std::endl;
    file << "   ()&_---()&\\&\\|&&-&&--%---()~" << std::endl;
    file << "             &&     \\|||" << std::endl;
    file << "                        |||" << std::endl;
    file << "                        |||" << std::endl;
    file << "                        |||" << std::endl;
    file << "                , -=-~  .-^- _" << std::endl;

	file.close();
}

