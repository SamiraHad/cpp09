# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsamira <hsamira@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/12 16:37:58 by hsamira           #+#    #+#              #
#    Updated: 2026/05/17 12:37:12 by hsamira          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = btc

CXX = c++

CXXFLAG = -Wall -Wextra -Werror -std=c++98 -Iheader

SRC = SRC/main.cpp SRC/BitcoinExchange.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME):$(OBJ)
	$(CXX) $(CXXFLAG) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAG) -c $< -o $@
	
clean: 
	rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
