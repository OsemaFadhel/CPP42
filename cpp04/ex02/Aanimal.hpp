/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Aaanimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:27:22 by ofadhel           #+#    #+#             */
/*   Updated: 2024/01/28 17:40:44 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>
#include <string>

class Aanimal
{
	protected:
		std::string type;
	public:
		Aanimal();
		Aanimal(std::string type);
		Aanimal(Aanimal const &src);
		Aanimal &operator=(Aanimal const &src);
		virtual ~Aanimal();
		std::string getType() const;
		virtual void makeSound() const = 0;
};

#endif
