# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/14 13:29:59 by asarikha          #+#    #+#              #
#    Updated: 2023/10/16 11:13:59 by asarikha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = DreamJobLogger
FILES = tests Account
COMPILE = c++ -Wall -Wextra -Werror

SRC = $(FILES:=.cpp)
HEADER = Account.hpp

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
	rm -f $(NAME)

.PHONY: re
re: fclean all