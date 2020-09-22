/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_get_pos.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/08 18:22:32 by okruitho      #+#    #+#                 */
/*   Updated: 2020/09/22 21:37:53 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int		ft_set_match(t_meta *md, t_vec2 pos, int dbl)
{
	char val;

	val = md->map.val[(int)pos.y][(int)pos.x];
	if (val == 'N' || val == 'E' || val == 'S' || val == 'W')
	{
		if (dbl == 1)
		{
			md->pos.x = -1;
			md->pos.y = -1;
			return (-2);
		}
		ft_set_pos_ang(md, val);
		md->pos.x = (double)pos.x + 0.51;
		md->pos.y = (double)pos.y + 0.51;
		return (1);
	}
	return (dbl);
}

void	ft_set_pos(t_meta *md)
{
	t_vec2	pos;
	int		dbl;

	pos.y = 0;
	pos.x = 0;
	dbl = 0;
	while (md->map.val[(int)pos.y])
	{
		pos.x = 0;
		while (md->map.val[(int)pos.y][(int)pos.x])
		{
			dbl = ft_set_match(md, pos, dbl);
			if (dbl == -2)
				return ;
			pos.x++;
		}
		pos.y++;
	}
}
