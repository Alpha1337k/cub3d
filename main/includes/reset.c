/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reset.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/04 19:23:14 by okruitho      #+#    #+#                 */
/*   Updated: 2020/06/08 18:09:15 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_reset_tex(t_meta *md)
{
	int x;

	x = 0;
	while (x < 5)
	{
		md->tx[x].i.img = 0;
		x++;
	}
}

void	ft_reset_md(t_meta *md)
{
	md->angle = 0;
	md->arg = 0;
	md->fc[0] = 0;
	md->fc[1] = 0;
	md->i[0].img = 0;
	md->i[1].img = 0;
	md->i[0].addr = 0;
	md->i[1].addr = 0;
	ft_reset_tex(md);
	md->res.x = 0;
	md->res.y = 0;
	md->pos.x = -1;
	md->pos.y = -1;
	md->mlx = 0;
	md->win = 0;
	md->map.unp = 0;
	md->map.val = 0;
	md->map.width = 0;
	md->map.height = 0;
}
