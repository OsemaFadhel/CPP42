# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 20:07:09 by ofadhel           #+#    #+#              #
#    Updated: 2024/01/22 18:12:14 by ofadhel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

SRCS = megaphone.cpp

FLAGS = -Wall -Wextra -Werror -std=c++98

OBJS	= $(SRCS:.cpp=.o)

CPP		= g++

%.o: %.cpp
			$(CPP) -c $< -o $@


all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(OBJS) $(SRC) -o $(NAME) $(FLAGS)

clean:
	rm -rf $(NAME) $(OBJS)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
