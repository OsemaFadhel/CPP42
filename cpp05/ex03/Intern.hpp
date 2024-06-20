/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:10:25 by ofadhel           #+#    #+#             */
/*   Updated: 2024/06/20 12:28:36 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "AForm.hpp"

class Intern
{
	private:
		AForm *createShrubberyCreationForm(const std::string &target);
		AForm *createRobotomyRequestForm(const std::string &target);
		AForm *createPresidentialPardonForm(const std::string &target);
	public:
		Intern();
		~Intern();
		Intern(Intern const &src);
		Intern &operator=(Intern const &src);
		AForm *makeForm(std::string formName, std::string target);
		AForm *createShrubberyCreationForm(std::string target);
		AForm *createRobotomyRequestForm(std::string target);
		AForm *createPresidentialPardonForm(std::string target);
};

#endif
