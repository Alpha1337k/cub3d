/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/10 21:52:38 by okruitho      #+#    #+#                 */
/*   Updated: 2020/06/10 21:52:40 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_get_splits(char const *s, char c)
{
	size_t	x;
	size_t	rval;

	rval = 0;
	x = 0;
	while (s[x] != 0)
	{
		if (x == 0 && s[x] != c)
			rval++;
		if (s[x] == c && s[x + 1] != c && s[x + 1] != 0)
			rval++;
		x++;
	}
	return (rval);
}

static size_t	ft_splitlen(char const *s, char c)
{
	size_t i;

	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (i);
}

static char		*ft_splitit(char const *s, char c, char **rv)
{
	char	*rval;
	size_t	x;
	size_t	size;

	rval = 0;
	x = 0;
	size = ft_splitlen(&s[0], c);
	if (size == (unsigned long)-1)
		return (0);
	rval = (char *)malloc(sizeof(char) * size + 1);
	if (rval == 0)
		return (ft_clrarr(rv));
	while (s[x] != '\0' && s[x] != c)
	{
		rval[x] = s[x];
		x++;
	}
	rval[x] = 0;
	if (rval[0] == 0)
	{
		free(rval);
		return (0);
	}
	return (rval);
}

static char		**ft_set_split(char const *s, char c, char **rval)
{
	char	*temp;
	int		i;
	int		x;

	x = 0;
	i = 0;
	temp = 0;
	while (s[x] != 0 && rval != 0)
	{
		if (x == 0 && s[x] != c)
			temp = ft_splitit(s, c, rval);
		else if (s[x] == c && s[x + 1] != c)
			temp = ft_splitit(&s[x + 1], c, rval);
		if (temp != 0 && rval != 0)
		{
			rval[i] = temp;
			i++;
		}
		temp = 0;
		x++;
	}
	rval[i] = 0;
	return (rval);
}

char			**ft_split(char const *s, char c)
{
	char	**rval;
	size_t	x;

	if (s == 0)
		return (0);
	x = ft_get_splits(s, c);
	rval = malloc(sizeof(char *) * (x + 1));
	if (rval == 0)
		return (0);
	rval = ft_set_split(s, c, rval);
	rval[x] = 0;
	return (rval);
}
