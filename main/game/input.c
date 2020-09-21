/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/07 04:51:54 by okruitho      #+#    #+#                 */
/*   Updated: 2020/09/21 19:16:30 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

/*
** This gem handles all the inputs, puts them in an array when pressed down.
** Supports 8 keypresses at once.
*/

int		ft_set_keyup(int key, t_meta *md)
{
	int x;

	x = 0;
	if (key == 0)
		key = -1;
	while (x != 8)
	{
		if (md->keydown[x] == key)
			md->keydown[x] = 0;
		x++;
	}
	return (0);
}

int		ft_set_keydown(int key, t_meta *md)
{
	int x;

	x = 0;
	if (key == 0)
		key = -1;
	if (key == KEYPRESS_ESC)
		ft_exit(md);
	while (x != 8)
	{
		if (md->keydown[x] == key)
			break ;
		if (md->keydown[x] == 0)
		{
			md->keydown[x] = key;
			break ;
		}
		x++;
	}
	return (0);
}
