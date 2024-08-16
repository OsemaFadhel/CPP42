/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:45:51 by ofadhel           #+#    #+#             */
/*   Updated: 2024/08/16 11:20:51 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <list>
#include <string>
#include <cstring>
#include <stdio.h>

class RPN
{
	private:
		std::stack<int, std::list<int> > _stack;
	public:
		RPN();
		~RPN();
		RPN &operator=(RPN const &obj);
		RPN(RPN const &obj);
		void execute(std::string const &av);
		void calculate(char c);
		void check(std::string const &av);
};

#endif
