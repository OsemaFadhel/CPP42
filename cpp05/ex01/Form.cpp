/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 15:53:23 by ofadhel           #+#    #+#             */
/*   Updated: 2024/04/13 15:59:23 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string const name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

Form::~Form()
{
}

Form::Form(Form const &src)
{
	*this = src;
}

Form &Form::operator=(Form const &src)
{
	_grade = src.getGrade();
	return (*this);
}

std::string Form::getName() const
{
	return (_name);
}

int Form::getGrade() const
{
	return (_grade);
}

void Form::incrementGrade()
{
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	else
		_grade--;
}

void Form::decrementGrade()
{
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	else
		_grade++;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too Low");
}

std::ostream &operator<<(std::ostream &out, Form const &src)
{
	out << src.getName() << ", Form grade " << src.getGrade();
	return (out);
}
