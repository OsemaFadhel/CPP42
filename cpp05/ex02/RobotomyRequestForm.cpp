/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:47:12 by ofadhel           #+#    #+#             */
/*   Updated: 2024/06/10 15:29:06 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45)
{
	_target = target;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : AForm(src)
{
	_target = src._target;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &src)
{
	if (this == &src)
		_target = src._target;
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();
	if (this->getSigned() == false)
		throw FormNotSignedException();

	std::cout << "brrrr     drrrrr   papapapap" << std::endl;

	int	i;
	if (i % 2)
		std::cout << _target << " has been robotomized." << std::endl;
	else
		std::cout << _target << " robotomization failed!!!" << std::endl;
}
