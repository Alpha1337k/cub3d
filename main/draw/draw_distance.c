/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_distance.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/06 22:14:31 by okruitho      #+#    #+#                 */
/*   Updated: 2020/08/04 23:06:16 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

char	ft_trace_ray(t_vec2_d *ray, t_vec2_d *dir, t_vec2 *t, t_meta *md)
{
	if (t->y == 0)
	{
		ray->x += dir->x;
		t->y = 1;
	}
	else
	{
		ray->y += dir->y;
		t->y = 0;
	}
	return (md->map.val[(int)(ray->y)][(int)(ray->x)]);
}

t_cast	ft_cast_ray(t_meta *md, t_cast *sprite, t_vec2_d dir, t_vec2 *t)
{
	t_vec2_d	ray;
	char		rayval;

	rayval = 1;
	dir.x *= 0.01;
	dir.y *= 0.01;
	ray.y = md->pos.y;
	ray.x = md->pos.x;
	while (rayval != '1' && rayval != 0)
	{
		rayval = ft_trace_ray(&ray, &dir, t, md);
		if (rayval == '2' && sprite->len == 0)
			*sprite = ft_get_sprt_data(md, &ray, t, &dir);
	}
	return (ft_get_cast_data(md, &ray, t, 0));
}
