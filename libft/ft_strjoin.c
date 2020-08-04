/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/02 23:34:54 by okruitho      #+#    #+#                 */
/*   Updated: 2020/06/10 21:55:39 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char		*rval;
	size_t		x;
	size_t		i;

	if (s1 == 0 || s2 == 0)
		return (0);
	i = ft_strlen(s2) + ft_strlen(s1);
	rval = malloc(sizeof(char) * (i + 1));
	x = 0;
	i = 0;
	if (rval == 0)
		return (0);
	while (s1[x] != 0)
	{
		rval[x] = s1[x];
		x++;
	}
	while (s2[i] != 0)
	{
		rval[x] = s2[i];
		x++;
		i++;
	}
	rval[x] = '\0';
	return (rval);
}
