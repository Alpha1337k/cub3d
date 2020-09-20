/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_refine.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/06 22:00:03 by okruitho      #+#    #+#                 */
/*   Updated: 2020/09/20 20:55:36 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

t_vec2_d		ft_get_true_impact(t_meta *md, t_vec2_d *ray, t_vec2 *t)
{
	t_vec2_d mray;

	mray.x = ray->x;
	mray.y = ray->y;
	if (t->y == 0)
	{
		if (mray.y > md->pos.y && t->y == 0)
			mray.y = floor(mray.y);
		else if (mray.y < md->pos.y && t->y == 0)
			mray.y = ceil(mray.y);
	}
	else
	{
		if (mray.x > md->pos.x && t->y == 1)
			mray.x = floor(mray.x);
		else if (mray.x < md->pos.x && t->y == 1)
			mray.x = ceil(mray.x);
	}
	return (mray);
}

t_wdir			ft_get_dir(t_meta *md, t_vec2_d *ray, int side)
{
	if (ray->y < md->pos.y && side == 0)
		return (NO);
	else if (ray->y > md->pos.y && side == 0)
		return (SO);
	else if (ray->x > md->pos.x && side == 1)
		return (WE);
	else if (ray->x < md->pos.x && side == 1)
		return (EA);
	return (ER);
}

int				ft_get_xof(t_meta *md, t_vec2_d *ray, int side, t_wdir tex)
{
	if (side == 1)
		return ((ray->y - floor(ray->y)) * md->tx[tex].p.x);
	else if (side == 0)
		return ((ray->x - floor(ray->x)) * md->tx[tex].p.x);
	return (0);
}

double			ft_get_len(t_meta *md, t_vec2_d *ray, t_vec2 *t)
{
	double len;
	double angle;

	len = sqrt(pow(md->pos.x - ray->x, 2) + pow(md->pos.y - ray->y, 2));
	angle = ((double)t->x * (double)FOV / (double)md->res.x) - FOV / 2.0;
	len *= (cos(angle * RAD));
	return (len);
}

t_cast			ft_get_cast_data(t_meta *md, t_vec2_d *ray, t_vec2 *t, int spr)
{
	t_cast rval;

	*ray = ft_get_true_impact(md, ray, t);
	rval.len = ft_get_len(md, ray, t);
	if (spr == 0)
		rval.dir = ft_get_dir(md, ray, t->y);
	else
		rval.dir = SP;
	rval.x_of = ft_get_xof(md, ray, t->y, rval.dir);
	return (rval);
}
