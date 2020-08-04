/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/10 22:02:13 by okruitho      #+#    #+#                 */
/*   Updated: 2020/06/10 22:02:14 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
