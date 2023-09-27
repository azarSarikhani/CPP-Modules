# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asarikha <asarikha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/14 13:29:59 by asarikha          #+#    #+#              #
#    Updated: 2023/08/29 14:37:52 by asarikha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ClapTrap
FILES = main ClapTrap
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
COMPILE = c++ -Wall -Wextra -Werror -std=c++98

SRC = $(FILES:=.cpp)
INCLUDE = -I ClapTrap.hpp
HEADER = ClapTrap.hpp

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