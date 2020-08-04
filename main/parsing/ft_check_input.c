/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_check_input.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/25 23:27:21 by okruitho      #+#    #+#                 */
/*   Updated: 2020/06/24 16:33:55 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../includes/cube3d.h"

int			ft_throw_error(char *s, t_meta *md)
{
	ft_printf("ERROR!\n%s\n", s);
	ft_exit(md);
	return (0);
}

int			ft_check_image_load(t_meta *md)
{
	int x;

	x = 0;
	while (x < 5)
	{
		if (md->tx[x].i.img == 0)
			return (0);
		x++;
	}
	return (1);
}

int			ft_check_fc(int *fc)
{
	int f;
	int c;

	f = (fc[0] >> (8 * 3)) & 0xff;
	c = (fc[1] >> (8 * 3)) & 0xff;
	if (f == 0 || c == 0)
		return (1);
	return (0);
}

int			ft_check_input(t_meta *md)
{
	if (md->res.x <= 0 || md->res.y <= 0)
		return (ft_throw_error("Negative res", md));
	if (ft_check_fc(md->fc) == 1)
		return (ft_throw_error("Invalid floor / ceiling color.", md));
	if (ft_check_image_load(md) == 0)
		return (ft_throw_error("Textured not loaded, missing?", md));
	if (md->pos.x == -1 && md->pos.y == -1)
		return (ft_throw_error("No player position defined. Double?", md));
	if (md->map.val == 0 || ft_init_flood(md) == 2)
		return (ft_throw_error("Map not fully enclosed!", md));
	return (1);
}
