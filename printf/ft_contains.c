/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_contains.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/10 22:01:15 by okruitho      #+#    #+#                 */
/*   Updated: 2020/06/10 22:01:16 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_contains(const char *arr, char *c, int len)
{
	int x;
	int i;

	x = 0;
	while (x < len && arr[x] != 0)
	{
		i = 0;
		while (c[i] != 0)
		{
			if (c[i] == arr[x])
				return (1);
			i++;
		}
		x++;
	}
	return (0);
}
