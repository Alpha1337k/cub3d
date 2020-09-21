/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/21 19:13:44 by okruitho      #+#    #+#                 */
/*   Updated: 2020/09/21 19:39:54 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	ft_move_forward(t_meta *md)
{
	if (md->map.val[(int)md->pos.y][(int)(md->pos.x + md->dir.x * 0.1)] != '1')
		md->pos.x += md->dir.x * 0.1;
	if (md->map.val[(int)(md->pos.y + md->dir.y * 0.1)][(int)md->pos.x] != '1')
		md->pos.y += md->dir.y * 0.1;
}

void	ft_move_back(t_meta *md)
{
	if (md->map.val[(int)md->pos.y][(int)(md->pos.x - md->dir.x * 0.1)] != '1')
		md->pos.x -= md->dir.x * 0.1;
	if (md->map.val[(int)(md->pos.y - md->dir.y * 0.1)][(int)md->pos.x] != '1')
		md->pos.y -= md->dir.y * 0.1;
}

void	ft_move_left(t_meta *md)
{
	if (md->map.val[(int)md->pos.y][(int)(md->pos.x + md->dir.y * 0.1)] != '1')
		md->pos.x += md->dir.y * 0.1;
	if (md->map.val[(int)(md->pos.y - md->dir.x * 0.1)][(int)md->pos.x] != '1')
		md->pos.y -= md->dir.x * 0.1;
}

void	ft_move_right(t_meta *md)
{
	if (md->map.val[(int)md->pos.y][(int)(md->pos.x - md->dir.y * 0.1)] != '1')
		md->pos.x -= md->dir.y * 0.1;
	if (md->map.val[(int)(md->pos.y + md->dir.x * 0.1)][(int)md->pos.x] != '1')
		md->pos.y += md->dir.x * 0.1;
}

int		ft_move_player(t_meta *md)
{
	int		x;

	x = 0;
	while (x != 8)
	{
		if (md->keydown[x] == KEYPRESS_W)
			ft_move_forward(md);
		else if (md->keydown[x] == KEYPRESS_S)
			ft_move_back(md);
		else if (md->keydown[x] == KEYPRESS_D)
			ft_move_right(md);
		else if (md->keydown[x] == KEYPRESS_A)
			ft_move_left(md);
		else if (md->keydown[x] == KEYPRESS_R)
			ft_turn_right(md);
		else if (md->keydown[x] == KEYPRESS_L)
			ft_turn_left(md);
		x++;
	}
	return (0);
}
