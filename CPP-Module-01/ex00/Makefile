# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asarikha <asarikha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/14 13:29:59 by asarikha          #+#    #+#              #
#    Updated: 2023/08/11 16:29:24 by asarikha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Zambie
FILES = main Zombie newZombie randomChump
COMPILE = c++ -Wall -Wextra -Werror

SRC = $(FILES:=.cpp)
HEADER = Zombie.hpp

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