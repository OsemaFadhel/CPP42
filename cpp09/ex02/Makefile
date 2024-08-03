# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/23 19:36:25 by ofadhel           #+#    #+#              #
#    Updated: 2024/08/03 22:29:36 by ofadhel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe

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
