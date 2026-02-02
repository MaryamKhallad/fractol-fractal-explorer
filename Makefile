NAME = fractol

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

SRC = src/events.c src/fractals.c src/initial.c src/main.c src/render.c src/utils.c
OBJ = $(SRC:.c=.o)

LIBFT_PATH = ./src/libft
LIBFT_LIB = $(LIBFT_PATH)/libft.a

MLX_PATH = ./src/mlx
MLXFLAGS = -L$(MLX_PATH) -lmlx -lXext -lX11 -lm
INCLUDES = -I$(MLX_PATH) -I$(LIBFT_PATH)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBFT_LIB) $(MLXFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT_LIB):
	make -C $(LIBFT_PATH)

clean:
	make clean -C $(LIBFT_PATH)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
