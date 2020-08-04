# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: okruitho <okruitho@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/30 20:45:21 by okruitho       #+#    #+#                 #
#    Updated: 2019/11/19 20:19:54 by okruitho      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_isascii.c ft_isdigit.c ft_isprint.c ft_isalpha.c ft_isalnum.c \
  ft_bzero.c  ft_calloc.c ft_itoa.c ft_putnbr_fd.c ft_putendl_fd.c \
  ft_putchar_fd.c ft_putstr_fd.c ft_strlen.c ft_strdup.c ft_memcmp.c \
  ft_strtrim.c ft_toupper.c ft_tolower.c ft_memmove.c ft_strlcpy.c \
  ft_memchr.c ft_strrchr.c ft_memcpy.c ft_strchr.c ft_memccpy.c ft_strncmp.c \
  ft_memset.c ft_atoi.c ft_strnstr.c ft_strjoin.c ft_substr.c ft_split.c \
  ft_strlcat.c ft_strmapi.c ft_clrarr.c\

OBJ = ft_isascii.o ft_isdigit.o ft_isprint.o ft_isalpha.o ft_isalnum.o \
  ft_bzero.o  ft_calloc.o ft_itoa.o ft_putnbr_fd.o ft_putendl_fd.o \
  ft_putchar_fd.o ft_putstr_fd.o ft_strlen.o ft_strdup.o ft_memcmp.o \
  ft_strtrim.o ft_toupper.o ft_tolower.o ft_memmove.o ft_strlcpy.o \
  ft_memchr.o ft_strrchr.o ft_memcpy.o ft_strchr.o ft_memccpy.o ft_strncmp.o \
  ft_memset.o ft_atoi.o ft_strnstr.o ft_strjoin.o ft_substr.o ft_split.o \
  ft_strlcat.o ft_strmapi.o ft_clrarr.o\

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRC)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean:
	rm -rf $(OBJ) $(NAME)

re: fclean all
