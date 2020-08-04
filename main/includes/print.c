/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/04 19:53:08 by okruitho      #+#    #+#                 */
/*   Updated: 2020/06/10 20:06:03 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
** This file stores all the functions printing values
*/

#include "cube3d.h"

void		ft_print_meta(t_meta *md)
{
	ft_printf("R.x:%d R.y:%d\n", md->res.x, md->res.y);
	ft_printf("Ceiling Color:\t%u\n", md->fc[1]);
	ft_printf("Floor Color:\t%u\n", md->fc[0]);
	ft_printf("NO:\t%p\n", md->tx[0].i.img);
	ft_printf("SO:\t%p\n", md->tx[1].i.img);
	ft_printf("WE:\t%p\n", md->tx[2].i.img);
	ft_printf("EA:\t%p\n", md->tx[3].i.img);
	ft_printf("S:\t%p\n", md->tx[4].i.img);
	ft_printf("POS:\t%d, %d\n", (int)md->pos.x, (int)md->pos.y);
}

void		ft_print_map_flood(char **map)
{
	int x;
	int y;

	y = 0;
	while (map[y] != 0)
	{
		x = 0;
		while (map[y][x] != 0)
		{
			if (map[y][x] == 'A')
			{
				ft_printf("\033[0;31mA\033[0m");
			}
			else
				ft_printf("%c", map[y][x]);
			x++;
		}
		ft_printf("$\n");
		y++;
	}
}

void		ft_print_map(t_meta *md)
{
	int x;
	int y;

	y = 0;
	x = 0;
	while (y < md->map.height)
	{
		x = 0;
		ft_printf("||");
		while (md->map.val[y][x] != 0)
		{
			if (x == (int)md->pos.x && y == (int)md->pos.y)
				ft_printf("P");
			else
				ft_printf("%c", md->map.val[y][x]);
			x++;
		}
		ft_printf("$\n");
		y++;
	}
}
