# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omaly <omaly@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/18 19:25:08 by omaly             #+#    #+#              #
#    Updated: 2025/11/10 14:22:30 by omaly            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project settings
NAME := fdf
SRC_DIR := src
BUILD_DIR := build
LIB_DIR := lib
BIN_DIR := bin

# Compiler settings
CC := cc
CFLAGS := -Wall -Wextra -Werror

# Libft
LIBFT_DIR := $(LIB_DIR)/libft
LIBFT_LIB := $(LIBFT_DIR)/libft.a

# Mlx
MLX_DIR := $(LIB_DIR)/mlx
MLX_LIB := $(MLX_DIR)/libmlx.a $(MLX_DIR)/libmlx_Linux.a

# Build tools
RM = rm -rf

# Source files
SRC =	$(SRC_DIR)/main.c \
		$(SRC_DIR)/fdf_init.c \
		$(SRC_DIR)/error.c \
		$(SRC_DIR)/parser/parse_map.c \
		$(SRC_DIR)/parser/calc_map_size.c

PARSER_SRCS	:=	$(SRC_DIR)/parser/parse_map.c \
				$(SRC_DIR)/parser/calc_map_size \

UTILS_SRCS	:=	$(SRC_DIR)/utils/is_whitespace.c \
				$(SRC_DIR)/utils/count_words.c

# FDF Object files
OBJS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC))

all: $(NAME)

$(NAME): dir $(OBJS) $(MLX_LIB) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(OBJS) \
	-L$(LIBFT_DIR) -lft \
	-L$(MLX_DIR) -lmlx_Linux \
	-L/usr/lib -lXext -lX11 -lm -lz \
	-o $(BIN_DIR)/$(NAME)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

# Create Object Files
$(BUILD_DIR)/%.o: dir $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

dir:
	mkdir -p $(BUILD_DIR) $(BIN_DIR)

clean:
	$(RM) $(BUILD_DIR) $(BIN_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MLX_DIR) fclean

re: fclean all

.PHONY = NAME all clean fclean
