# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asarikha <asarikha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/14 13:29:59 by asarikha          #+#    #+#              #
#    Updated: 2023/08/29 15:04:58 by asarikha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ScavTrap
FILES = main ClapTrap ScavTrap
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
COMPILE = c++ -Wall -Wextra -Werror -std=c++98

SRC = $(FILES:=.cpp)
INCLUDE = -I ClapTrap.hpp -I ScavTrap.hpp
HEADER = ClapTrap.hpp ScavTrap.hpp

OBJDIR = obj/
OBJ = $(SRC:.cpp=.o)
OBJS		= $(addprefix $(OBJDIR), $(OBJ))

.PHONY: all
all: $(NAME)

$(OBJDIR):
	@mkdir $(OBJDIR)

$(OBJS): $(OBJDIR)%.o:%.cpp
	$(COMPILE) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJDIR) $(OBJS) $(HEADER)
	$(COMPILE) $(OBJS) -o $(NAME) $(INCLUDE)

.PHONY: clean
clean:
	@echo "Cleaning object files..."
	rm -rf $(OBJDIR)

.PHONY: fclean
fclean: clean
	rm $(NAME)

.PHONY: re
re: fclean all