/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_wall.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/06 21:58:58 by okruitho      #+#    #+#                 */
/*   Updated: 2020/08/04 18:10:26 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	ft_draw_wall_part(t_vec3 c, t_cast cast, t_img *img, t_meta *md)
{
	double			y;
	double			incr;
	int				x_of_calc;
	unsigned int	color;

	incr = (double)md->tx[cast.dir].p.y / (double)(c.z - c.y);
	x_of_calc = cast.x_of * md->tx[cast.dir].i.bits_per_pixel / 8;
	y = 0;
	ft_draw_vline(c.x, ft_vecmrg(0, c.y), img, md);
	while (c.y < c.z)
	{
		if (c.y >= 0 && c.y < md->res.y)
		{
			color = ft_get_color(md->tx[cast.dir].i.addr + ((int)y * \
					md->tx[cast.dir].i.line_length + x_of_calc));
			if (cast.dir != SP || ((char)color != 0 && color != 0))
				ft_pixel_put(img, c.x, c.y, color);
		}
		c.y++;
		y += incr;
	}
	ft_draw_vline(c.x, ft_vecmrg(c.y, md->res.y), img, md);
}

void	ft_draw_walls(t_meta *md, t_img *img)
{
	t_vec2 t;
	t_cast cast;
	t_cast sprite;
	double angle;

	t.x = 0;
	angle = md->angle - FOV / 2;
	while (t.x < md->res.x)
	{
		t.y = 1;
		sprite.len = 0;
		cast = ft_cast_ray(md, &sprite, ft_atc(angle), &t);
		angle += (double)FOV / (double)md->res.x;
		ft_draw_ray(t, cast, img, md);
		if (sprite.len != 0 && sprite.x_of > 0 && sprite.x_of < md->tx[SP].p.x)
			ft_draw_ray(t, sprite, img, md);
		t.x++;
	}
}
