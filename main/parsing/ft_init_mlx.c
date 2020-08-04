/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_init_mlx.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/06 17:48:54 by okruitho      #+#    #+#                 */
/*   Updated: 2020/08/04 22:11:48 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

t_img	ft_load_frame(t_meta *md)
{
	t_img rval;

	rval.img = mlx_new_image(md->mlx, md->res.x, md->res.y);
	rval.addr = mlx_get_data_addr(rval.img, &rval.bits_per_pixel, \
		&rval.line_length, &rval.endian);
	return (rval);
}

void	ft_init_mlx(t_meta *md)
{
	if (!md->arg)
		md->win = mlx_new_window(md->mlx, md->res.x, md->res.y, "cube3d");
	if (md->win == 0 && !md->arg)
		ft_throw_error("mlx window failed to initialize", md);
	md->i[0] = ft_load_frame(md);
	md->i[1] = ft_load_frame(md);
	if (!md->i[0].addr || !md->i[0].img || !md->i[1].addr || !md->i[1].img)
		ft_throw_error("frames failed to load", md);
}
