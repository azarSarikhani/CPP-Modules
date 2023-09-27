# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azarsarikhani <azarsarikhani@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/14 13:29:59 by asarikha          #+#    #+#              #
#    Updated: 2023/08/16 11:50:14 by azarsarikha      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = "Harl 2.0"
FILES = main Harl
COMPILE = c++ -Wall -Wextra -Werror

SRC = $(FILES:=.cpp)
HEADER = Harl.hpp

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