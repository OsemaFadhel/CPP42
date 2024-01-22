/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebookClass.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:27:13 by ofadhel           #+#    #+#             */
/*   Updated: 2024/01/21 17:00:55 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOKCLASS_HPP
# define PHONEBOOKCLASS_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <cstdio>
# include "contactClass.hpp"

class PhoneBook
{
	private:
		Contact contacts[8];
		int index;
		int contactCount;
	public:
		PhoneBook();
		~PhoneBook();
		void add();
		void search();
		void printContacts();
		void printIndex(int index);
};

#endif
