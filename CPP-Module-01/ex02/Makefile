# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asarikha <asarikha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/14 13:29:59 by asarikha          #+#    #+#              #
#    Updated: 2023/08/14 09:32:17 by asarikha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = HI_THIS_IS_BRAIN
FILES = main
COMPILE = c++ -Wall -Wextra -Werror

SRC = $(FILES:=.cpp)

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