/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_exit.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/04 18:04:21 by okruitho      #+#    #+#                 */
/*   Updated: 2020/06/24 16:40:22 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

/*
** Here we free all the malloced exising vars, than exit
*/

void	ft_freemap(char **map, int height)
{
	int y;

	y = 0;
	while (y < height && map[y] != 0)
	{
		free(map[y]);
		y++;
	}
	free(map);
}

void	ft_destroy_tex(t_meta *md)
{
	int x;

	x = 0;
	while (x < 5)
	{
		if (md->tx[x].i.img)
			mlx_destroy_image(md->mlx, md->tx[x].i.img);
		x++;
	}
}

void	ft_destroy_image(t_meta *md)
{
	if (md->i[0].img)
		mlx_destroy_image(md->mlx, md->i[0].img);
	if (md->i[1].img)
		mlx_destroy_image(md->mlx, md->i[1].img);
}

int		ft_exit(t_meta *md)
{
	ft_destroy_image(md);
	ft_destroy_tex(md);
	if (md->mlx)
		mlx_do_key_autorepeaton(md->mlx);
	if (md->win)
		mlx_destroy_window(md->mlx, md->win);
	if (md->map.status == 1)
		ft_freemap(md->map.val, md->map.height + 1);
	exit(0);
	return (0);
}
