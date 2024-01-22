# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 20:07:40 by ofadhel           #+#    #+#              #
#    Updated: 2024/01/21 00:52:45 by ofadhel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

SRC = PhoneBook.cpp main.cpp contact.cpp

FLAGS = -Wall -Wextra -Werror -std=c++98

OBJS 	= $(SRCS:.cpp=.o)

%.o: %.cpp
			c++ -c $< -o $@


all: $(NAME)

$(NAME): $(OBJS)
	c++ $(OBJS) $(SRC) -o $(NAME) $(FLAGS)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
