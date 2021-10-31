# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/20 21:02:59 by user42            #+#    #+#              #
#    Updated: 2021/10/31 02:48:56 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = clang
FLAGS = -Wall -Werror -Wextra
MLX_FLAGS = -L./minilibx_linux -lmlx_Linux -L/usr/bin -lX11 -lXext -lm 
MLX_INC = -Iminilibx_linux
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = -Iinclude -Ilibft
RM = rm -rf
LIBS = minilibx_linux
MYLIB = libft

SRC = $(INIT) $(KEYHANDLER) $(RENDER) $(GNL) $(PARSING) $(EXIT)

INIT = init.c init_struct.c
KEYHANDLER = handle_keypress.c play_moves.c exit_enabled.c
RENDER = img_pix_put.c render.c render_etc.c
GNL = get_next_line.c get_next_line_utils.c
PARSING = check_parsing.c parsing.c check_file.c
EXIT = exit.c free_map.c

INIT := $(INIT:%.c=init/%.c)
KEYHANDLER := $(KEYHANDLER:%.c=keyhandler/%.c)
RENDER := $(RENDER:%.c=render/%.c)
GNL := $(GNL:%.c=get_next_line/%.c)
PARSING := $(PARSING:%.c=parsing/%.c)
EXIT := $(EXIT:%.c=exit/%.c)
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

all : $(NAME)

$(NAME): libs $(OBJ) $(INCLUDE:%.h=$(INC_DIR)/%.h)
	@echo "Compiling $(NAME)..."
	@$(CC) $(MLX_INC) $(INC_DIR) $(FLAGS) -o so_long src/so_long.c $(OBJ) -L$(MYLIB) -lft -lncurses $(MLX_FLAGS)
	@echo "Compilation success!"
	
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(@D)
	@echo "compiling $@..."
	@$(CC) $(FLAGS) $(MLX_INC) $(INC_DIR) -c $< -o $@

libs:
	@echo "Making libs..."
	@$(MAKE) -C $(LIBS)
	@$(MAKE) -C $(MYLIB)

bonus:
	@$(MAKE) -C bonus
	cp ./bonus/so_long .

clean : 
	@$(RM) $(OBJ_DIR)
	@$(MAKE) -C $(LIBS) clean
	@$(MAKE) -C $(MYLIB) clean
	@$(MAKE) -C bonus clean

fclean : clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(MYLIB) fclean
	@$(MAKE) -C bonus fclean

re : fclean all

debug: CFLAGS += -g
debug: fclean bonus
sanitize: CFLAGS += -fsanitize=address
sanitize: debug

.PHONY: all $(NAME) clean fclean libs re bonus debug