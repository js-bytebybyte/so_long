# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/08 14:19:41 by jsteenpu          #+#    #+#              #
#    Updated: 2023/08/08 14:42:57 by jsteenpu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Executable file / name
NAME = so_long.out

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directories
MAP_DIR = map
GNL_DIR = get_next_line
LIBFT_DIR = libft

# Source files
MAP_SRCS = $(wildcard $(MAP_DIR)/*.c)
GNL_SRCS = $(wildcard $(GNL_DIR)/*.c)
LIBFT_SRCS = $(wildcard $(LIBFT_DIR)/*.c)

# Object files
MAP_OBJS = $(MAP_SRCS:.c=.o)
GNL_OBJS = $(GNL_SRCS:.c=.o)
LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)

all: $(NAME)

# how is the executable file created ? 
# $^ refers to all the prerequisites = object files 
$(NAME): $(MAP_OBJS) $(GNL_OBJS) $(LIBFT_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(MAP_DIR)/%.o: $(MAP_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(GNL_DIR)/%.o: $(GNL_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(LIBFT_DIR)/%.o: $(LIBFT_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(MAP_OBJS) $(GNL_OBJS) $(LIBFT_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
