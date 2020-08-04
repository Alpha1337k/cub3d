/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstrl.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/10 22:02:05 by okruitho      #+#    #+#                 */
/*   Updated: 2020/06/10 22:02:06 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putstrl(char *s, int max)
{
	int x;

	x = 0;
	if (s == 0)
		return (0);
	while (s[x] != 0 && x < max)
	{
		ft_putchar(s[x]);
		x++;
	}
	return (x);
}
