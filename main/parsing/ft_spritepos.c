/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_spritepos.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/18 22:31:46 by okruitho      #+#    #+#                 */
/*   Updated: 2020/09/20 21:09:26 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int		ft_set_sprite(t_meta *md)
{
	int		x;
	t_vec2	pos;

	x = 0;
	pos.y = 0;
	while (md->map.val[pos.y])
	{
		pos.x = 0;
		while (md->map.val[pos.y][pos.x])
		{
			if (md->map.val[pos.y][pos.x] == '2')
				x++;
			pos.x++;
		}
		pos.y++;
	}
	md->spritecount = x;
	return (x);
}

void	ft_get_spritepos(t_meta *md)
{
	t_vec2	pos;
	int		x;

	x = 0;
	md->sprite = malloc(sizeof(t_sprite) * ft_set_sprite(md));
	if (!md->sprite)
		ft_throw_error("malloc fail for sprites", md);
	pos.y = 0;
	while (md->map.val[pos.y])
	{
		pos.x = 0;
		while (md->map.val[pos.y][pos.x])
		{
			if (md->map.val[pos.y][pos.x] == '2')
			{
				md->sprite[x].pos = pos;
				x++;
			}
			pos.x++;
		}
		pos.y++;
	}
}
