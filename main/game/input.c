/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/07 04:51:54 by okruitho      #+#    #+#                 */
/*   Updated: 2020/06/24 17:32:45 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

/*
** This gem handles all the inputs, puts them in an array when pressed down.
** Supports 8 keypresses at once.
*/

int		ft_set_keyup(int key, t_meta *md)
{
	int x;

	x = 0;
	if (key == 0)
		key = -1;
	while (x != 8)
	{
		if (md->keydown[x] == key)
			md->keydown[x] = 0;
		x++;
	}
	return (0);
}

int		ft_set_keydown(int key, t_meta *md)
{
	int x;

	x = 0;
	if (key == 0)
		key = -1;
	if (key == KEYPRESS_ESC)
		ft_exit(md);
	while (x != 8)
	{
		if (md->keydown[x] == key)
			break ;
		if (md->keydown[x] == 0)
		{
			md->keydown[x] = key;
			break ;
		}
		x++;
	}
	return (0);
}

void	ft_move(t_meta *md, t_vec2_d d)
{
	char val;

	val = md->map.val[(int)(md->pos.y + d.y / 10)]\
	[(int)(md->pos.x + d.x / 10)];
	if (val == '0')
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
