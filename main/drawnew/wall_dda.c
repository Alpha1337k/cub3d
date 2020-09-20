/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wall_dda.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/20 20:55:53 by okruitho      #+#    #+#                 */
/*   Updated: 2020/09/20 20:56:32 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	ft_dda(t_dda_wall *dw, t_meta *md)
{
	while (md->map.val[dw->mappos.y][dw->mappos.x] != '1')
	{
		if (dw->sidedist.x < dw->sidedist.y)
		{
			dw->sidedist.x += dw->deltadist.x;
			dw->mappos.x += dw->step.x;
			dw->side = 0;
		}
		else
		{
			dw->sidedist.y += dw->deltadist.y;
			dw->mappos.y += dw->step.y;
			dw->side = 1;
		}
	}
}

void	ft_setup_dda(t_dda_wall *dw, t_meta *md)
{
	if (dw->raydir.x < 0)
	{
		dw->step.x = -1;
		dw->sidedist.x = (md->pos.x - dw->mappos.x) * dw->deltadist.x;
	}
	else
	{
		dw->step.x = 1;
		dw->sidedist.x = (dw->mappos.x + 1.0 - md->pos.x) * dw->deltadist.x;
	}
	if (dw->raydir.y < 0)
	{
		dw->step.y = -1;
		dw->sidedist.y = (md->pos.y - dw->mappos.y) * dw->deltadist.y;
	}
	else
	{
		dw->step.y = 1;
		dw->sidedist.y = (dw->mappos.y + 1.0 - md->pos.y) * dw->deltadist.y;
	}
}

void	ft_calculate_dda(t_dda_wall *dw, t_meta *md, t_vec3 *coords)
{
	int lineheight;

	if (dw->side == 0)
		dw->perpdist = (dw->mappos.x - md->pos.x + (1 - dw->step.x) / 2) \
		/ dw->raydir.x;
	else
		dw->perpdist = (dw->mappos.y - md->pos.y + (1 - dw->step.y) / 2) \
		/ dw->raydir.y;
	lineheight = (int)(md->res.y / dw->perpdist);
	coords->y = -lineheight / 2 + md->res.y / 2;
	coords->z = lineheight / 2 + md->res.y / 2;
}
