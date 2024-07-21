/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:56:29 by ofadhel           #+#    #+#             */
/*   Updated: 2024/07/21 21:51:56 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <string>

template <typename T>
class Array {
	private:
		T* elements;
		unsigned int length;
	public:
		Array() : elements(NULL), length(0) {}
		Array(unsigned int n) : elements(new T[n]()), length(n) {}
		Array(const Array &src) : elements(new T[src.length]()), length(src.length) {
			for (unsigned int i = 0; i < length; ++i)
				elements[i] = src.elements[i];
		}
		Array &operator=(const Array &src) {
			if (this != &src) {
				delete[] elements;
				length = src.length;
				elements = new T[length]();
				for (unsigned int i = 0; i < length; ++i)
					elements[i] = src.elements[i];
			}
			return *this;
		}
		~Array() {
			delete[] elements;
		}

		T &operator[](unsigned int index) {
			if (index >= length)
				throw OoBException();
			return elements[index];
		}

		unsigned int size() const {
			return length;
		}

		class OoBException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return "Out of bounds";
				}
		};
};

#endif
