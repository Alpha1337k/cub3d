# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: okruitho <okruitho@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/06/02 12:59:03 by okruitho      #+#    #+#                  #
#    Updated: 2020/06/10 20:59:55 by okruitho      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftgnl.a

SRC = get_next_line.c get_next_line_utils.c

OBJ = get_next_line.o get_next_line_utils.o

$(NAME):
	gcc -O3 -c $(SRC)
	ar rc $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean:
	rm -rf $(NAME)
re: fclean all