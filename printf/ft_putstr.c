/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/10 21:59:50 by okruitho      #+#    #+#                 */
/*   Updated: 2020/06/10 21:59:52 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putstr(char *s)
{
	int x;

	if (s == 0)
		return (0);
	x = 0;
	while (s[x] != 0)
	{
		ft_putchar(s[x]);
		x++;
	}
	return (x);
}
