/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wallnorm1.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/18 22:47:51 by okruitho      #+#    #+#                 */
/*   Updated: 2020/09/19 00:53:04 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	ft_dda(t_dda_wall *dw, t_meta *md)
{
	while (md->map.val[dw->mappos.y][dw->mappos.x] != '1')
	{
		if(dw->sidedist.x < dw->sidedist.y)
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

void ft_setup_dda(t_dda_wall *dw, t_meta *md)
{
	if(dw->raydir.x < 0)
	{
		dw->step.x = -1;
		dw->sidedist.x = (md->pos.x - dw->mappos.x) * dw->deltadist.x;
	}
	else
	{
		dw->step.x = 1;
		dw->sidedist.x = (dw->mappos.x + 1.0 - md->pos.x) * dw->deltadist.x;
	}
	if(dw->raydir.y < 0)
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

void ft_setup_raydir(int x, t_meta *md, t_dda_wall *dw)
{
	double camerax;

	camerax = 2 * x / (double)md->res.x - 1;
	dw->raydir.x = md->dir.x + md->plane.x * camerax;
	dw->raydir.y = md->dir.y + md->plane.y * camerax;
	dw->deltadist.x = fabs(1 / dw->raydir.x);
	dw->deltadist.y = fabs(1 / dw->raydir.y);
}

void	ft_calculate_dda(t_dda_wall *dw, t_meta *md, t_vec3 *coords)
{
	if(dw->side == 0)
		dw->perpdist = (dw->mappos.x - md->pos.x + (1 - dw->step.x) / 2) / dw->raydir.x;
	else          
		dw->perpdist  = (dw->mappos.y - md->pos.y + (1 - dw->step.y) / 2) / dw->raydir.y;
	int lineHeight = (int)(md->res.y / dw->perpdist);
	coords->y = -lineHeight / 2 + md->res.y / 2;
	coords->z = lineHeight / 2 + md->res.y / 2;
}

void	ft_cast_wall(t_dda_wall *dw, t_meta *md, t_img *img, t_vec3 *coords)
{
	if(dw->side == 0)
		dw->wallx = md->pos.y + dw->perpdist * dw->raydir.y;
	else
		dw->wallx = md->pos.x + dw->perpdist * dw->raydir.x;
	dw->wallx -= floor(dw->wallx);
	int texX = (int)(dw->wallx * (double)(md->tx[SP].p.x));
	if(dw->side == 0 && dw->raydir.x > 0) texX = md->tx[SP].p.x - texX - 1;
	if(dw->side == 1 && dw->raydir.y < 0) texX = md->tx[SP].p.x - texX - 1;
	t_cast cst;
	if (dw->mappos.y < md->pos.y && dw->side == 1)
		cst.dir = NO;
	else if (dw->mappos.y > md->pos.y && dw->side == 1)
		cst.dir = SO;
	else if (dw->mappos.x > md->pos.x && dw->side == 0)
		cst.dir = WE;
	else if (dw->mappos.x < md->pos.x && dw->side == 0)
		cst.dir = EA;
	cst.x_of = texX;
	ft_draw_wall_part(*coords, cst, img, md);
}

void    ft_dda_walls(t_meta *md, t_img *img)
{
	t_dda_wall	dw;
	t_vec3		coords;
	for(int x = 0; x < md->res.x; x++)
	{
		ft_setup_raydir(x, md, &dw);
		coords.x = x;
		dw.mappos.x = (int)md->pos.x;
		dw.mappos.y = (int)md->pos.y;
		ft_setup_dda(&dw, md);
		ft_dda(&dw, md);
		ft_calculate_dda(&dw, md, &coords);
		ft_cast_wall(&dw, md, img, &coords);
		md->z_buf[x] = dw.perpdist;
	}
}
