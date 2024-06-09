/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 15:53:23 by ofadhel           #+#    #+#             */
/*   Updated: 2024/06/09 16:49:40 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string const name, int gradetoSign, int gradeToExecute) : _name(name), _gradeToSign(gradetoSign), _gradeToExecute(gradeToExecute)
{
	_signed = false;
	if (gradetoSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	else if (gradetoSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

Form::~Form()
{
}

Form::Form(Form const &src) : _name(src._name), _signed(src._signed) ,_gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
}

Form &Form::operator=(Form const &src)
{
	if (this != &src)
		_signed = src._signed;
	return (*this);
}

std::string Form::getName() const
{
	return (_name);
}

bool Form::getSigned() const
{
	return (_signed);
}

int Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void Form::beSigned(Bureaucrat &b)
{
	if(b.getGrade() <= _gradeToSign)
		_signed = true;
	else
		throw GradeTooLowException();
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
	out << src.getName() << ", Form grade to sign: " << src.getGradeToSign() << ", Form grade to execute: " << src.getGradeToExecute() << ", Form is signed: " << src.getSigned();
	return (out);
}
