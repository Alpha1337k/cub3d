/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/07 04:51:54 by okruitho      #+#    #+#                 */
/*   Updated: 2020/09/17 20:32:33 by okruitho      ########   odam.nl         */
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
	if (val == '0' || val == 'N' || val == 'E' || val == 'S' || val == 'W')
	{
		md->pos.x += d.x / 10;
		md->pos.y += d.y / 10;
	}
}

int		ft_move_player(t_meta *md)
{
	int x;
	double rotSpeed = 0.05;

	x = 0;
	while (x != 8)
	{
		if (md->keydown[x] == KEYPRESS_W)
		{
 	    	if(md->map.val[(int)md->pos.y][(int)(md->pos.x + md->dir.x * 0.1)] != '1') md->pos.x += md->dir.x * 0.1;
    		if(md->map.val[(int)(md->pos.y + md->dir.y * 0.1)][(int)md->pos.x] != '1') md->pos.y += md->dir.y * 0.1;	
		}
		// else if (md->keydown[x] == KEYPRESS_A)
		// 	ft_move(md, ft_atc(md->angle - 90));
		else if (md->keydown[x] == KEYPRESS_S)
		{
 	    	if(md->map.val[(int)md->pos.y][(int)(md->pos.x - md->dir.x * 0.1)] != '1') md->pos.x -= md->dir.x * 0.1;
    		if(md->map.val[(int)(md->pos.y - md->dir.y * 0.1)][(int)md->pos.x] != '1') md->pos.y -= md->dir.y * 0.1;
		}
		// else if (md->keydown[x] == KEYPRESS_D)
		// 	ft_move(md, ft_atc(md->angle + 90));
		else if (md->keydown[x] == KEYPRESS_L)
		{
			md->angle += 2;		
			double oldDirX = md->dir.x;
			md->dir.x = md->dir.x * cos(-rotSpeed) - md->dir.y * sin(-rotSpeed);
			md->dir.y = oldDirX * sin(-rotSpeed) + md->dir.y * cos(-rotSpeed);
			double oldPlaneX = md->plane.x;
			md->plane.x = md->plane.x * cos(-rotSpeed) - md->plane.y * sin(-rotSpeed);
			md->plane.y = oldPlaneX * sin(-rotSpeed) + md->plane.y * cos(-rotSpeed);
		}
		else if (md->keydown[x] == KEYPRESS_R)
		{
			md->angle += 2;
			//both camera direction and camera plane must be rotated
			double oldDirX = md->dir.x;
			md->dir.x = md->dir.x * cos(rotSpeed) - md->dir.y * sin(rotSpeed);
			md->dir.y = oldDirX * sin(rotSpeed) + md->dir.y * cos(rotSpeed);
			double oldPlaneX = md->plane.x;
			md->plane.x = md->plane.x * cos(rotSpeed) - md->plane.y * sin(rotSpeed);
			md->plane.y = oldPlaneX * sin(rotSpeed) + md->plane.y * cos(rotSpeed);
		}
		x++;
	}
	return (0);
}
