NAME = so_long
CC = clang
MLX_FLAGS = -L./minilibx_linux -lmlx_Linux -L/usr/bin -lX11 -lXext -lm -lz
MLX_INC = -Iminilibx_linux
INC = -Iinclude
SRC = rec.c 
MAIN = main.c

all : $(name)
	@$(CC) $(INC) $(MLX_INC) $(MAIN) $(SRC) $(MLX_FLAGS) -o $(NAME)

clean : 
	@rm -f $(NAME)
