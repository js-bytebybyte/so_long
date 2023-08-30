# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/08 14:19:41 by jsteenpu          #+#    #+#              #
#    Updated: 2023/08/30 12:42:10 by jsteenpu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Executable file / name
NAME = so_long

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
LINKS = -Lmlx -lmlx -framework OpenGL -framework Appkit

# Directories
GAME_DIR = game
GNL_DIR = get_next_line
LIBFT_DIR = libft

# Source files
GAME_SRCS = $(wildcard $(GAME_DIR)/*.c)
GNL_SRCS = $(wildcard $(GNL_DIR)/*.c)
LIBFT_SRCS = $(wildcard $(LIBFT_DIR)/*.c)

# Object files
GAME_OBJS = $(GAME_SRCS:.c=.o)
GNL_OBJS = $(GNL_SRCS:.c=.o)
LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(GAME_OBJS) $(GNL_OBJS) $(LIBFT_OBJS)
	$(CC) $(CFLAGS) $(LINKS) -o $@ $^

$(GAME_DIR)/%.o: $(GAME_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(GNL_DIR)/%.o: $(GNL_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(LIBFT_DIR)/%.o: $(LIBFT_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(GAME_OBJS) $(GNL_OBJS) $(LIBFT_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
