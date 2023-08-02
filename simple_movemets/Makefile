# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/02 16:12:39 by jsteenpu          #+#    #+#              #
#    Updated: 2023/08/02 16:30:11 by jsteenpu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = simple.out

# compiling
CC = cc
FLAGS = -Wall -Wextra -Werror
LINKS = -lmlx - framework OpenGL -framework Appkit 

# objects and sources
SRC = main.c hooks.c image.c
OBJ = $(SRC:.c=.o)

all: $(NAME) 

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(LINKS) $(OBJ) -o $(NAME)

$(OBJ): $(SRC)
	$(CC) $(FLAGS) -c $(OBJ)

exe: all
	./$(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME) 

re: fclean all
