/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook_class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:27:13 by ofadhel           #+#    #+#             */
/*   Updated: 2024/01/19 17:52:16 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

# include <iostream>
# include <string>
# include <iomanip>
//# include "contact_class.hpp"

class Contact
{
	public:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string	phone_number;
		std::string darkest_secret;
		Contact();
		~Contact();
		void print();
};

class PhoneBook
{
	private:
		Contact contacts[8];
		int index;
	public:
		PhoneBook();
		~PhoneBook();
		void add();
		void search();
		void print_contacts();
};

#endif
