/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move_legacy.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/21 19:13:47 by okruitho      #+#    #+#                 */
/*   Updated: 2020/09/21 19:16:19 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	ft_move(t_meta *md, t_vec2_d d)
{
	char val;

	val = md->map.val[(int)(md->pos.y + d.y / 10)]\
	[(int)(md->pos.x + d.x / 10)];
	if (val == '0' || val == 'N' || val == 'E' || val == 'S' || val == 'W')
	{
		md->pos.x += d.x / 10;
		md->pos.y += d.y / 10;
	}
}

int		ft_move_player(t_meta *md)
{
	int x;

	x = 0;
	while (x != 8)
	{
		if (md->keydown[x] == KEYPRESS_W)
			ft_move(md, ft_atc(md->angle));
		else if (md->keydown[x] == KEYPRESS_A)
			ft_move(md, ft_atc(md->angle - 90));
		else if (md->keydown[x] == KEYPRESS_S)
			ft_move(md, ft_atc(md->angle - 180));
		else if (md->keydown[x] == KEYPRESS_D)
			ft_move(md, ft_atc(md->angle + 90));
		else if (md->keydown[x] == KEYPRESS_L)
			md->angle += 2;
		else if (md->keydown[x] == KEYPRESS_R)
			md->angle -= 2;
		x++;
	}
	return (0);
}
