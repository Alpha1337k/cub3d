/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/10 22:00:44 by okruitho      #+#    #+#                 */
/*   Updated: 2020/06/10 22:00:46 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int		ft_print_xchar(char c, int count)
{
	int x;

	x = 0;
	while (x < count)
	{
		ft_putchar(c);
		x++;
	}
	return (x);
}

char	*ft_tostr(char c)
{
	char *rval;

	rval = malloc(sizeof(char) * 2);
	if (rval == 0)
		return (0);
	rval[0] = c;
	rval[1] = '\0';
	return (rval);
}

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
