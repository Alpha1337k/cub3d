/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move1.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/21 19:36:46 by okruitho      #+#    #+#                 */
/*   Updated: 2020/09/21 19:40:07 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	ft_turn_right(t_meta *md)
{
	double	olddir;
	double	oldplane;

	olddir = md->dir.x;
	md->dir.x = md->dir.x * cos(-0.05) - md->dir.y * sin(-0.05);
	md->dir.y = olddir * sin(-0.05) + md->dir.y * cos(-0.05);
	oldplane = md->plane.x;
	md->plane.x = md->plane.x * cos(-0.05) - md->plane.y * sin(-0.05);
	md->plane.y = oldplane * sin(-0.05) + md->plane.y * cos(-0.05);
}

void	ft_turn_left(t_meta *md)
{
	double	olddir;
	double	oldplane;

	olddir = md->dir.x;
	md->dir.x = md->dir.x * cos(0.05) - md->dir.y * sin(0.05);
	md->dir.y = olddir * sin(0.05) + md->dir.y * cos(0.05);
	oldplane = md->plane.x;
	md->plane.x = md->plane.x * cos(0.05) - md->plane.y * sin(0.05);
	md->plane.y = oldplane * sin(0.05) + md->plane.y * cos(0.05);
}
