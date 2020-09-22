/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   drawing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/17 19:16:39 by okruitho      #+#    #+#                 */
/*   Updated: 2020/09/22 21:36:43 by okruitho      ########   odam.nl         */
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

void	ft_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_draw_vline(int x, t_vec2 c, t_img *img, t_meta *md)
{
	int				y;
	unsigned int	clr;

	y = c.x;
	if (y > md->res.y / 2)
		clr = md->fc[0];
	else
		clr = md->fc[1];
	if (y >= md->res.y)
		return ;
	while (y < c.y && y < md->res.y)
	{
		if (y < md->res.y && y >= 0)
			ft_pixel_put(img, x, y, clr);
		y++;
	}
}
