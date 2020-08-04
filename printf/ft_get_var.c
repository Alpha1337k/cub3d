/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_get_var.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/10 22:01:38 by okruitho      #+#    #+#                 */
/*   Updated: 2020/06/10 22:01:43 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_filter_var(int x, char *c)
{
	while (ft_contains(c, "diuxXcsp%", 1) == 0)
	{
		c++;
		x++;
	}
	return (x);
}

int	ft_asterisk_count(const char *c)
{
	int passed_dot;
	int size;
	int prc;

	passed_dot = -1;
	size = 0;
	prc = 0;
	while (ft_isalpha(c[0]) == 0 && c[0] != '%')
	{
		if (c[0] == '*' && passed_dot == -1)
			size += 1;
		if (c[0] == '*' && passed_dot == 1)
			prc += 1;
		if (c[0] == '.' && c[1] == '*')
			passed_dot = 1;
		c++;
	}
	if (c[0] == '%' && size == 0 && prc == 0)
		return (-3);
	return ((size + prc) * passed_dot);
}
