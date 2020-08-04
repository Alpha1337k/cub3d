/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   addons.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/04 21:26:39 by okruitho      #+#    #+#                 */
/*   Updated: 2020/06/10 21:07:33 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int		ft_strclen(char *s, char c)
{
	int x;

	x = 0;
	while (s[x] && s[x] != c)
	{
		x++;
	}
	return (x);
}

char	*ft_strldup(const char *s1, int n)
{
	int		x;
	char	*rval;

	x = 0;
	rval = (char *)malloc(sizeof(char) * n + 1);
	if (rval != 0)
	{
		while (x != n)
		{
			rval[x] = s1[x];
			x++;
		}
	}
	rval[x] = 0;
	return (rval);
}
