# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: alpha_1337 <alpha_1337@student.codam.nl      +#+                      #
#                                                    +#+                       #
#    Created: 2019/11/10 04:46:52 by alpha_1337    #+#    #+#                  #
#    Updated: 2020/09/21 20:25:38 by okruitho      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #


SRC =	main/parsing/ft_check_input.c	\
		main/parsing/ft_check_map.c		\
		main/parsing/ft_get_pos.c		\
		main/parsing/ft_get_dir.c		\
		main/parsing/ft_init_mlx.c		\
		main/parsing/ft_load_image.c	\
		main/parsing/ft_parse_input.c	\
		main/parsing/ft_parse_map.c		\
		main/parsing/ft_spritepos.c		\
		main/game/bmp.c					\
		main/game/cube3d.c				\
		main/game/ft_exit.c				\
		main/game/input.c				\
		main/includes/addons.c			\
		main/includes/conversions.c		\
		main/includes/print.c			\
		main/includes/reset.c			\
		main/includes/rgb.c				\

FINAL = 	main/drawnew/algorithm.c		\
			main/drawnew/drawing.c			\
			main/drawnew/sprite.c			\
			main/drawnew/wall.c				\
			main/drawnew/wall_dda.c			\
			main/game/move.c				\
			main/game/move1.c				\

LEGACY =	main/draw/algorithm.c			\
			main/draw/draw_distance.c		\
			main/draw/draw_refine.c			\
			main/draw/draw_wall.c			\
			main/draw/draw.c				\
			main/game/move_legacy.c			\


NAME = cub3D

GNL = gnl/libftgnl.a

PRINTF = printf/libftprintf.a

LIBFT = libft/libft.a

MLX = mlx-mac/libmlx.dylib

LINUXMLX = minilibx-master/libmlx_Linux.a

FLAGS = -Wall -Werror -Wextra -O3

LINUXLIBS = -lXext -lX11 -lm -lz

MACLIBS =  -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(SRC)
	@$(MAKE) -C printf/
	@$(MAKE) -C gnl/
	@$(MAKE) -C libft/
	@$(MAKE) -C mlx-mac/
	@gcc -o $(NAME) $(SRC) $(FINAL) $(GNL) $(PRINTF) $(LIBFT) $(MLX) \
		$(MACLIBS) $(FLAGS)

.PHONY: clean fclean

linux:
	@$(MAKE) -C printf/
	@$(MAKE) -C gnl/
	@$(MAKE) -C libft/
	@$(MAKE) -C minilibx-master/
	@gcc -O3 -o $(NAME) $(SRC) $(GNL) $(PRINTF) $(LIBFT) $(LINUXMLX) \
		$(LINUXLIBS) -D LINUX=1

legacy:
	@$(MAKE) -C printf/
	@$(MAKE) -C gnl/
	@$(MAKE) -C libft/
	@$(MAKE) -C mlx-mac/
	@gcc -o $(NAME) $(SRC) $(LEGACY) $(GNL) $(PRINTF) $(LIBFT) $(MLX) \
		$(MACLIBS) $(FLAGS) -D LEGACY=1
clean:
	@rm -rf printf/*.o
	@rm -rf gnl/*.o
	@rm -rf libft/*.o
	@rm -rf minilibx-master/*.o minilibx-master/test/*.o \
			minilibx-master/test/mlx-test minilibx-master/libmlx.a

fclean:
	@rm -rf $(NAME)
	@rm -rf printf/*.o $(PRINTF)
	@rm -rf gnl/*.o $(GNL)
	@rm -rf libft/*.o $(LIBFT)
	@$(MAKE) -C mlx-mac/ clean
	@rm -rf $(MLX)
	@rm -rf $(LINUXMLX) minilibx-master/*.o minilibx-master/test/*.o \
			 minilibx-master/test/mlx-test minilibx-master/libmlx.a


run: re
	./cub3D maps/basic.cub

lrun: fclean linux
	./cub3D maps/basic.cub

re: fclean all
