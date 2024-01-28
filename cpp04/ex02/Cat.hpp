/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:50:43 by ofadhel           #+#    #+#             */
/*   Updated: 2024/01/28 17:42:03 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Aanimal.hpp"
#include "Brain.hpp"

class Cat : virtual public Aanimal
{
	private:
		Brain *brain;
	public:
		Cat();
		Cat(std::string type);
		Cat(Cat const &src);
		Cat &operator=(Cat const &src);
		~Cat();
		void makeSound() const override;
};

#endif
