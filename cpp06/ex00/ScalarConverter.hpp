/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:34:30 by ofadhel           #+#    #+#             */
/*   Updated: 2024/04/26 16:34:30 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <limits>
# include <cmath>

class ScalarConverter
{
	private:
		std::string _input;
	public:
		ScalarConverter();
		ScalarConverter(std::string input);
		ScalarConverter(ScalarConverter const &src);
		ScalarConverter &operator=(ScalarConverter const &src);
		~ScalarConverter();

		void setInput(std::string input);
		std::string getInput() const;
		void convert();
		void printChar();
		void printInt();
		void printFloat();
		void printDouble();
};

#endif
