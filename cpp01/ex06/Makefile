# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/23 19:36:25 by ofadhel           #+#    #+#              #
#    Updated: 2024/02/02 16:57:21 by ofadhel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = harlFilter

SRCS = $(wildcard *.cpp)

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
