# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: alpha_1337 <alpha_1337@student.codam.nl      +#+                      #
#                                                    +#+                       #
#    Created: 2019/11/10 04:46:52 by alpha_1337     #+#    #+#                 #
#    Updated: 2019/12/27 16:33:10 by okruitho      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRC = ft_atoi.c ft_contains.c ft_get_var.c ft_istype.c ft_itoa.c \
	ft_print_num.c ft_print_str.c ft_print_switch.c ft_printf.c ft_putchar.c \
	ft_gethex.c ft_putstr.c ft_putstrl.c ft_reverse.c ft_strdup.c \
	ft_strlen.c ft_getptr.c

OBJ = ft_atoi.o ft_contains.o ft_get_var.o ft_istype.o ft_itoa.o \
	ft_print_num.o ft_print_str.o ft_print_switch.o ft_printf.o ft_putchar.o \
	ft_gethex.o ft_putstr.o ft_putstrl.o ft_reverse.o ft_strdup.o \
	ft_strlen.o ft_getptr.o

NAME = libftprintf.a


all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRC)
	ar rcs $(NAME) $(OBJ)

.PHONY: clean fclean

clean:
	rm -rf $(OBJ)

fclean:
	rm -rf $(OBJ) $(NAME)

re: fclean all
