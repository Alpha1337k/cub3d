/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/06 23:26:20 by okruitho      #+#    #+#                 */
/*   Updated: 2020/06/10 21:06:00 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

int				get_next_line(int fd, char **line);
char			*ft_strnjoin(char *s1, char *s2, int ret);
size_t			ft_strlen(const char *s);
char			*ft_cut(char *s1, int ret);
int				ft_contains(const char *arr, char *c, int len);

#endif
