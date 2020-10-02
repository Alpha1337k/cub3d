/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_check_map.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/04 17:10:32 by okruitho      #+#    #+#                 */
/*   Updated: 2020/10/02 09:41:22 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"
#include <string.h>

int		ft_doublenl(char *unp)
{
	int x;

	x = 0;
	while (unp[x])
	{
		if (unp[x] == '\n' && unp[x + 1] == '\n' && ft_atoi(&unp[x + 2]) != 0)
			return (1);
		x++;
	}
	return (0);
}

t_vec2	ft_change_pos_adv(t_vec2 pos, int dir)
{
	if (dir == 4)
	{
		pos.x -= 1;
		pos.y -= 1;
	}
	else if (dir == 5)
	{
		pos.x -= 1;
		pos.y += 1;
	}
	else if (dir == 6)
	{
		pos.x += 1;
		pos.y -= 1;
	}
	else if (dir == 7)
	{
		pos.x += 1;
		pos.y += 1;
	}
	return (pos);
}

t_vec2	ft_change_pos(t_vec2 pos, int dir)
{
	if (dir > 3)
		return (ft_change_pos_adv(pos, dir));
	if (dir == 0)
		pos.y += 1;
	else if (dir == 1)
		pos.x += 1;
	else if (dir == 2)
		pos.y -= 1;
	else if (dir == 3)
		pos.x -= 1;
	return (pos);
}

int		ft_flood_map(char **map, t_vec2 pos, int dir, t_vec2 dm)
{
	int x;
	int rval;

	x = 0;
	rval = 0;
	pos = ft_change_pos(pos, dir);
	if ((map[pos.y] != 0 && (int)ft_strlen(map[pos.y]) > pos.x) && \
		(map[pos.y][pos.x] == 'A' || map[pos.y][pos.x] == '1'))
		return (1);
	if (pos.x >= dm.x || map[pos.y] == 0 || map[pos.y][pos.x] == ' ' || \
		map[pos.y][pos.x] == 0 || pos.y == 0 || pos.x == 0 || \
			(int)ft_strlen(map[pos.y]) < pos.x)
		return (2);
	map[pos.y][pos.x] = 'A';
	while (x < 8)
	{
		rval = ft_flood_map(map, pos, x, dm);
		if (rval == 2)
			return (2);
		x++;
	}
	return (0);
}

int		ft_init_flood(t_meta *md)
{
	char	**map;
	t_vec2	pos;
	int		rval;
	int		x;

	rval = 0;
	x = 0;
	pos.x = md->pos.x;
	pos.y = md->pos.y;
	if (ft_doublenl(md->map.unp) == 1 || pos.y == 0)
		return (2);
	map = ft_split(md->map.unp, '\n');
	if (map == 0)
		return (2);
	while (rval != 2 && x < 8)
	{
		rval = ft_flood_map(map, pos, x, \
		ft_vecmrg(md->map.width, md->map.height));
		x++;
	}
	ft_freemap(map, md->map.height + 1);
	return (rval);
}
