# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/23 19:36:25 by ofadhel           #+#    #+#              #
#    Updated: 2024/07/16 14:46:48 by ofadhel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out

SRCS = $(wildcard *.cpp)

FLAGS = -Wall -Wextra -Werror -Wshadow -Wno-shadow -std=c++98

OBJS	= $(SRCS:.cpp=.o)

CPP		= g++

%.o: %.cpp
			$(CPP) $(FLAGS) -c $< -o $@


all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(OBJS) $(SRC) -o $(NAME) $(FLAGS)

clean:
	rm -rf $(NAME) $(OBJS)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
