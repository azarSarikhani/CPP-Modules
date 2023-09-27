# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/14 13:29:59 by asarikha          #+#    #+#              #
#    Updated: 2023/09/25 12:58:14 by asarikha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = easyFind
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -g
COMPILE = $(CC) $(FLAGS)

FILES = main 
SRC_PATH	= src/
SRC = $(FILES:=.cpp)
SRCS = $(addprefix $(SRC_PATH),$(SRC))

INCLUDE = -I ./include/

OBJDIR = obj/
OBJ = $(SRC:.cpp=.o)
OBJS = $(addprefix $(OBJDIR), $(OBJ))

.PHONY: all clean fclean re

all: $(NAME)

$(OBJDIR):
	@mkdir $(OBJDIR)

$(OBJS): $(OBJDIR)%.o:$(SRC_PATH)%.cpp
	$(COMPILE) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJDIR) $(OBJS)
	$(COMPILE) $(OBJS) -o $(NAME) $(INCLUDE)

clean:
	@echo "Cleaning object files..."
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all