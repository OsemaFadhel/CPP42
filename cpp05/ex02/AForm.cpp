/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 15:53:23 by ofadhel           #+#    #+#             */
/*   Updated: 2024/06/09 18:16:39 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(std::string const name, int gradetoSign, int gradeToExecute) : _name(name), _gradeToSign(gradetoSign), _gradeToExecute(gradeToExecute)
{
	_signed = false;
	if (gradetoSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	else if (gradetoSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::~AForm()
{
}

AForm::AForm(AForm const &src) : _name(src._name), _signed(src._signed) ,_gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
}

AForm &AForm::operator=(AForm const &src)
{
	if (this != &src)
		_signed = src._signed;
	return (*this);
}

std::string AForm::getName() const
{
	return (_name);
}

bool AForm::getSigned() const
{
	return (_signed);
}

int AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

int AForm::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void AForm::beSigned(Bureaucrat &b)
{
	if(b.getGrade() <= _gradeToSign)
		_signed = true;
	else
		throw GradeTooLowException();
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > _gradeToExecute)
		throw GradeTooLowException();
	if (!_signed)
		throw FormNotSignedException();
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too Low");
}

std::ostream &operator<<(std::ostream &out, AForm const &src)
{
	out << src.getName() << ", AForm grade to sign: " << src.getGradeToSign() << ", AForm grade to execute: " << src.getGradeToExecute() << ", AForm is signed: " << src.getSigned();
	return (out);
}
