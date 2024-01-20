/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contactClass.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:27:45 by ofadhel           #+#    #+#             */
/*   Updated: 2024/01/20 22:49:31 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTCLASS_HPP
# define CONTACTCLASS_HPP

# include <iostream>
# include <string>
# include <iomanip>

class Contact
{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string	phoneNumber;
		std::string darkestSecret;
	public:
		Contact();
		~Contact();
		std::string getFirstName() const;
		void	setFirstName(std::string first_name);
		std::string getLastName() const;
		void	setLastName(std::string last_name);
		std::string getNickname() const;
		void	setNickname(std::string nickname);
		std::string getPhoneNumber() const;
		void	setPhoneNumber(std::string phone_number);
		std::string getDarkestSecret() const;
		void	setDarkestSecret(std::string darkest_secret);
};

#endif
