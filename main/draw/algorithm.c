/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithm.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/05 03:41:40 by okruitho      #+#    #+#                 */
/*   Updated: 2020/08/04 22:17:56 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

/*
** This function makes the frames and pushes them to the window
*/

int		ft_render(t_meta *md)
{
	static unsigned char i = 0;

	ft_move_player(md);
	ft_draw_walls(md, &md->i[i % 2]);
	if (md->arg)
	{
		ft_save_bmp(&md->i[i % 2], md);
		ft_exit(md);
	}
	mlx_put_image_to_window(md->mlx, md->win, md->i[i % 2].img, 0, 0);
	i++;
	return (0);
}
