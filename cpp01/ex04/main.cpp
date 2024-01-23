/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:36:34 by ofadhel           #+#    #+#             */
/*   Updated: 2024/01/23 19:59:23 by ofadhel          ###   ########.fr       */
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
	while (ifs)
	{
		ifs >> s1;
		if (s1 == s2)
			str += s2;
		else
			str += s1;
	}
	ofs << str;
	ifs.close();
	ofs.close();
	return (0);
}
