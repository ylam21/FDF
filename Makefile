# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omaly <omaly@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/18 19:25:08 by omaly             #+#    #+#              #
#    Updated: 2025/11/20 16:57:29 by omaly            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project settings
SRC_DIR := src
BUILD_DIR := build
LIB_DIR := lib
BIN_DIR := bin
NAME := $(BIN_DIR)/fdf

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
MAIN_SRCS =	$(SRC_DIR)/main.c \
			$(SRC_DIR)/has_fdf_extension.c \
			$(SRC_DIR)/hooks.c \
			$(SRC_DIR)/allocate_scene.c

GNL_SRCS :=	$(SRC_DIR)/utils/gnl/get_next_line.c \
			$(SRC_DIR)/utils/gnl/get_next_line_utils.c

PROJECTOR_SRCS	:=	$(SRC_DIR)/projector/transform.c

RENDERER_SRCS	:=	$(SRC_DIR)/renderer/render.c \
					$(SRC_DIR)/renderer/bresenham.c

PARSER_SRCS	:=	$(SRC_DIR)/parser/parse_map.c \
				$(SRC_DIR)/parser/parse_line.c \
				$(SRC_DIR)/parser/parse_token.c \

INIT_SRCS	:=	$(SRC_DIR)/init/camera_defaults_init.c \
				$(SRC_DIR)/init/mlx_defaults_init.c \
				$(SRC_DIR)/init/map_defaults_init.c \

UTILS_SRCS	:=	$(SRC_DIR)/utils/is_whitespace.c \
				$(SRC_DIR)/utils/count_words.c \
				$(SRC_DIR)/utils/fdf_atoi.c \
				$(SRC_DIR)/utils/is_sign.c \
				$(SRC_DIR)/utils/hex_to_int.c \
				$(SRC_DIR)/utils/print_error.c \
				$(SRC_DIR)/utils/free_fdf.c

SRCS = $(MAIN_SRCS) $(PARSER_SRCS) $(INIT_SRCS) $(UTILS_SRCS) $(RENDERER_SRCS) $(PROJECTOR_SRCS) $(GNL_SRCS)

# FDF Object files
OBJS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))

all: $(NAME)

$(NAME): $(OBJS) $(MLX_LIB) $(LIBFT_LIB) | $(BIN_DIR)
	$(CC) $(CFLAGS) $(OBJS) \
	-L$(LIBFT_DIR) -lft \
	-L$(MLX_DIR) -lmlx_Linux \
	-L/usr/lib -lXext -lX11 -lm -lz \
	-o $@

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Create Object Files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(BUILD_DIR) $(BIN_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MLX_DIR) fclean

re: fclean all

.PHONY: all clean fclean
