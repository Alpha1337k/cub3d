/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/10 21:52:17 by okruitho      #+#    #+#                 */
/*   Updated: 2020/06/10 21:52:19 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		ft_get_begin(char const *s1, char const *set)
{
	int x;
	int i;
	int found;

	x = 0;
	i = 0;
	while (s1[x] != 0)
	{
		found = 0;
		while (set[i] != 0 && found != 1)
		{
			if (set[i] == s1[x])
				found = 1;
			i++;
		}
		if (found == 0)
			return (x);
		i = 0;
		x++;
	}
	return (-1);
}

static int		ft_get_end(char const *s1, char const *set, int max)
{
	int x;
	int i;
	int found;

	x = max - 1;
	i = 0;
	while (s1[x] != 0)
	{
		found = 0;
		while (set[i] != 0 && found != 1)
		{
			if (set[i] == s1[x])
				found = 1;
			i++;
		}
		if (found == 0)
			return (x);
		i = 0;
		x--;
	}
	return (-1);
}

static char		*ft_settrim(char const *s1, int min, int max)
{
	char	*rval;
	int		m;
	int		x;

	x = 0;
	m = max - min + 1;
	rval = malloc(sizeof(char) * m + 1);
	if (rval == 0)
		return (0);
	while (x < m)
	{
		rval[x] = s1[x + min];
		x++;
	}
	rval[m] = '\0';
	return (rval);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int		min;
	int		max;
	char	*rval;
	int		s_len;

	if (s1 == 0)
		return (0);
	rval = 0;
	s_len = ft_strlen(s1);
	min = ft_get_begin(s1, set);
	if (min == -1)
	{
		rval = malloc(sizeof(char));
		rval[0] = 0;
		return (rval);
	}
	max = ft_get_end(s1, set, s_len);
	rval = ft_settrim(s1, min, max);
	return (rval);
}
