/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/05 00:19:08 by okruitho      #+#    #+#                 */
/*   Updated: 2020/06/24 17:58:32 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

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
	while (y < c.y)
	{
		ft_pixel_put(img, x, y, clr);
		y++;
	}
}

void	ft_draw_ray(t_vec2 t, t_cast cast, t_img *img, t_meta *md)
{
	t_vec3	c;
	int		h;

	if (cast.len <= 0)
		return ;
	h = (int)(md->res.y / cast.len);
	c.x = t.x;
	c.y = (md->res.y - h) / 2;
	c.z = (md->res.y + h) / 2;
	if (c.y < -md->res.y * 4)
		c.y = -md->res.y * 4;
	if ((unsigned int)c.z > (unsigned int)md->res.y * 4)
		c.z = md->res.y * 4;
	ft_draw_wall_part(c, cast, img, md);
}
