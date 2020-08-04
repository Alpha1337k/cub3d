/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_load_image.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/17 15:12:16 by okruitho      #+#    #+#                 */
/*   Updated: 2020/06/10 20:20:34 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

t_tex	ft_load_img(t_meta *md, char *str)
{
	t_tex tx;

	while (*str == ' ')
		str++;
	tx.i.img = mlx_png_file_to_image(md->mlx, str, &tx.p.x, &tx.p.y);
	if (!tx.i.img)
		return (tx);
	tx.i.addr = mlx_get_data_addr(tx.i.img, &tx.i.bits_per_pixel, \
	&tx.i.line_length, &tx.i.endian);
	return (tx);
}
