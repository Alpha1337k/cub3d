/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wall.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/18 22:47:51 by okruitho      #+#    #+#                 */
/*   Updated: 2020/09/20 20:56:56 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	ft_setup_raydir(int x, t_meta *md, t_dda_wall *dw)
{
	double camerax;

	camerax = 2 * x / (double)md->res.x - 1;
	dw->raydir.x = md->dir.x + md->plane.x * camerax;
	dw->raydir.y = md->dir.y + md->plane.y * camerax;
	dw->deltadist.x = fabs(1 / dw->raydir.x);
	dw->deltadist.y = fabs(1 / dw->raydir.y);
}

void	ft_cast_wall(t_dda_wall *dw, t_meta *md, t_img *img, t_vec3 *coords)
{
	t_cast	cst;
	int		tex_x;

	if (dw->mappos.y < md->pos.y && dw->side == 1)
		cst.dir = NO;
	else if (dw->mappos.y > md->pos.y && dw->side == 1)
		cst.dir = SO;
	else if (dw->mappos.x > md->pos.x && dw->side == 0)
		cst.dir = WE;
	else if (dw->mappos.x < md->pos.x && dw->side == 0)
		cst.dir = EA;
	if (dw->side == 0)
		dw->wallx = md->pos.y + dw->perpdist * dw->raydir.y;
	else
		dw->wallx = md->pos.x + dw->perpdist * dw->raydir.x;
	dw->wallx -= floor(dw->wallx);
	tex_x = (int)(dw->wallx * (double)(md->tx[cst.dir].p.x));
	if (dw->side == 0 && dw->raydir.x > 0)
		tex_x = md->tx[cst.dir].p.x - tex_x - 1;
	if (dw->side == 1 && dw->raydir.y < 0)
		tex_x = md->tx[cst.dir].p.x - tex_x - 1;
	cst.x_of = tex_x;
	ft_draw_wall_part(*coords, cst, img, md);
}

void	ft_dda_walls(t_meta *md, t_img *img)
{
	t_dda_wall	dw;
	t_vec3		coords;
	int			x;

	x = 0;
	while (x < md->res.x)
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
		x++;
	}
}

void	ft_draw_walls(t_meta *md, t_img *img)
{
	ft_dda_walls(md, img);
	ft_dda_sprites(md, img);
}

