# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azarsarikhani <azarsarikhani@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/14 13:29:59 by asarikha          #+#    #+#              #
#    Updated: 2023/08/23 12:27:50 by azarsarikha      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Fixed
FILES = main Fixed
COMPILE = c++ -Wall -Wextra -Werror -std=c++98

SRC = $(FILES:=.cpp)
HEADER = Fixed.hpp

.PHONY: all
all: $(NAME)

$(NAME): $(SRC)
	$(COMPILE) $(SRC) -o $(NAME) 

.PHONY: clean
clean:
	@echo "Cleaning object files..."
	rm -f *.o

.PHONY: fclean
fclean: clean
	rm $(NAME)

.PHONY: re
re: fclean all