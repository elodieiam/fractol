NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBS = ./libft/libft.a ./minilibx/libmlx_Linux.a -lX11 -lXext -lm
RM = rm -f
SRC = src/main.c\
	src/burning.c\
	src/check_arguments_utils.c\
	src/color_push_pixel.c\
	src/julia.c\
	src/mandelbrot.c\
	src/mlx_hook.c\
	src/start_fractal_utils1.c\
	src/start_fractal_utils2.c\
	src/zoom_plane.c\
	src/shift_plane.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	
$(NAME): $(OBJ) ./src/fractol.h
	@echo "Making libft..."
	@make -sC ./libft
	@echo "Making MiniLibX..."
	@make -sC ./minilibx
	@echo "Making fractol..."
	@$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $@
	@echo "Ready !"

clean:
	$(RM) $(OBJ)
	make clean -sC ./libft
	make clean -sC ./minilibx

fclean: clean
	$(RM) $(NAME)
	make fclean -C ./libft

re: fclean all

.PHONY : all bonus clean flclean re

norme :
	norminette $(SRCS) fractol.h libft