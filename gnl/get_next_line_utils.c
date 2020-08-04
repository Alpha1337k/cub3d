/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/06 23:26:29 by okruitho      #+#    #+#                 */
/*   Updated: 2020/06/10 21:06:33 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_cut(char *s1, int ret)
{
	char	*rval;
	int		x;

	x = 0;
	rval = malloc(sizeof(char) * (ret + 1));
	if (rval == 0)
		return (NULL);
	while (x < ret)
	{
		rval[x] = s1[x];
		x++;
	}
	rval[x] = 0;
	return (rval);
}

char	*ft_strnjoin(char *s1, char *s2, int ret)
{
	char		*rval;
	size_t		x;
	size_t		i;

	i = ret + ft_strlen(s1);
	rval = malloc(sizeof(char) * (i + 1));
	if (rval == 0)
		return (0);
	x = 0;
	i = 0;
	while (s1[x] != 0)
	{
		rval[x] = s1[x];
		x++;
	}
	while (s2[i] != 0 && ret != 0)
	{
		rval[x] = s2[i];
		x++;
		i++;
		ret--;
	}
	rval[x] = '\0';
	return (rval);
}

size_t	ft_strlen(const char *s)
{
	int x;

	x = 0;
	if (s == 0)
		return (0);
	while (s[x] != 0)
	{
		x++;
	}
	return (x);
}

int		ft_contains(const char *arr, char *c, int len)
{
	int x;
	int i;

	x = 0;
	if (arr == 0)
		return (-1);
	while (x < len && arr[x] != 0)
	{
		i = 0;
		while (c[i] != 0)
		{
			if (c[i] == arr[x])
				return (1);
			i++;
		}
		x++;
	}
	return (0);
}
