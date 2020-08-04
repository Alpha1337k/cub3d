/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 17:26:52 by okruitho      #+#    #+#                 */
/*   Updated: 2020/06/10 21:54:40 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		len;
	int		x;
	char	*rval;

	x = 0;
	len = 0;
	while (s1[len] != '\0')
		len++;
	len++;
	rval = (char *)malloc(sizeof(char) * len);
	if (rval != 0)
	{
		while (x != len)
		{
			rval[x] = s1[x];
			x++;
		}
	}
	return (rval);
}
