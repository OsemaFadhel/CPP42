/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:36:34 by ofadhel           #+#    #+#             */
/*   Updated: 2024/02/02 15:22:22 by ofadhel          ###   ########.fr       */
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
	if (ifs.peek() == std::ifstream::traits_type::eof())
	{
		std::cout << "Error: file is empty" << std::endl;
		return (1);
	}
	std::string str;
	std::string line;
	while (std::getline(ifs, line))
	{
		int pos;
		while ((pos = line.find(s1)) != -1)
		{
			line.erase(pos, s1.length());
			line.insert(pos, s2);
		}
		str += line;
		str += '\n';
	}
	filename += ".replace";
	std::ofstream ofs(filename);
	if (!ofs)
	{
		std::cout << "Error: could not create file" << std::endl;
		return (1);
	}
	ofs << str;
	ifs.close();
	ofs.close();
	return (0);
}
