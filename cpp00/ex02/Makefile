# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/21 00:45:58 by ofadhel           #+#    #+#              #
#    Updated: 2024/01/21 00:53:10 by ofadhel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = account

SRC = tests.cpp Account.cpp

OBJS 	= $(SRCS:.cpp=.o)

FLAGS = -Wall -Wextra -Werror -std=c++98

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
