# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/20 21:02:59 by user42            #+#    #+#              #
#    Updated: 2021/10/21 18:40:06 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = clang
FLAGS = -Wall -Werror -Wextra
MLX_FLAGS = -L./minilibx_linux -lmlx_Linux -L/usr/bin -lX11 -lXext -lm -lz
MLX_INC = -Iminilibx_linux
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = -Iinclude -Iimages
RM = rm -rf
LIBS = minilibx_linux

SRC = $(INIT) $(KEYHANDLER) $(RENDER)

INIT = init.c
KEYHANDLER = handle_keypress.c
RENDER = img_pix_put.c render.c render_etc.c

INIT := $(INIT:%.c=init/%.c)
KEYHANDLER := $(KEYHANDLER:%.c=keyhandler/%.c)
RENDER := $(RENDER:%.c=render/%.c)
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

all : $(NAME)

$(NAME): libs $(OBJ) $(INCLUDE:%.h=$(INC_DIR)/%.h)
	@echo "Compiling $(NAME)..."
	@$(CC) $(MLX_INC) $(INC_DIR) $(FLAGS) -o so_long src/so_long.c $(OBJ) $(MLX_FLAGS)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(@D)
	@echo "compiling $@..."
	@$(CC) $(FLAGS) $(MLX_INC) $(INC_DIR) -c $< -o $@
libs:
	@echo "Making libs..."
	@$(MAKE) -C $(LIBS)
clean : 
	@$(RM) $(OBJ_DIR)
	@$(MAKE) -C $(LIBS) clean

fclean : clean
	@$(RM) so_long
re : fclean all
