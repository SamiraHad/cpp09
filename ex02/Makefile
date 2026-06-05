# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsamira <hsamira@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/22 12:11:59 by hsamira           #+#    #+#              #
#    Updated: 2026/05/22 12:12:52 by hsamira          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe

CXX = c++

CXXFLAG = -Wall -Wextra -Werror -std=c++98 -Iheader

SRC = SRC/main.cpp SRC/PmergeMe.cpp

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