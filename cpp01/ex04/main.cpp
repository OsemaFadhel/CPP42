/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:36:34 by ofadhel           #+#    #+#             */
/*   Updated: 2024/01/30 17:59:09 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Three parameters in the following order: a filename and two strings" << std::endl;
		return (1);
	}
	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];
	std::ifstream ifs(filename);
	if (!ifs)
	{
		std::cout << "Error: could not open file" << std::endl;
		return (1);
	}
	std::string str;
	filename += ".replace";
	std::ofstream ofs(filename);
	if (!ofs)
	{
		std::cout << "Error: could not open file" << std::endl;
		return (1);
	}
	std::string line;
	while (ifs) // use getline() instead
	{
		ifs >> line;
		if (s1 == line)
			str += s2;
		else
			str += line;
		if (line == "\n")
			str += "\n";
		else
			str += " ";
	}
	ofs << str;
	ifs.close();
	ofs.close();
	return (0);
}
