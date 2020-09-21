/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_get_dir.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/21 20:24:52 by okruitho      #+#    #+#                 */
/*   Updated: 2020/09/21 20:27:24 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	ft_set_dir_sw(t_meta *md, char val)
{
	if (val == 'S')
	{
		md->dir.x = 0;
		md->dir.y = 1;
		md->plane.x = -0.66;
		md->plane.y = 0;
	}
	if (val == 'W')
	{
		md->dir.x = -1;
		md->dir.y = 0;
		md->plane.x = 0;
		md->plane.y = -0.66;
	}
}

void	ft_set_dir(t_meta *md, char val)
{
	if (val == 'N')
	{
		md->dir.x = 0;
		md->dir.y = -1;
		md->plane.x = 0.66;
		md->plane.y = 0;
	}
	if (val == 'E')
	{
		md->dir.x = 1;
		md->dir.y = 0;
		md->plane.x = 0;
		md->plane.y = 0.66;
	}
	ft_set_dir_sw(md, val);
}

void	ft_set_pos_ang(t_meta *md, char val)
{
	if (val == 'N')
		md->angle = -90;
	else if (val == 'E')
		md->angle = 0;
	else if (val == 'S')
		md->angle = 90;
	else if (val == 'W')
		md->angle = 180;
	if (!LEGACY)
		ft_set_dir(md, val);
}
