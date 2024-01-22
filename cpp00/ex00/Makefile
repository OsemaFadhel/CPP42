# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 20:07:09 by ofadhel           #+#    #+#              #
#    Updated: 2024/01/22 15:41:06 by ofadhel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

SRC = megaphone.cpp

FLAGS = -Wall -Wextra -Werror -std=c++98

OBJS 	= $(SRCS:.cpp=.o)

%.o: %.cpp
			c++ -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
		c++ $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
